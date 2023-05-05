/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:08:51 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 09:09:00 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fill_ans(int **ans, int t_row, int t_col)
{
	int	max;
	int	*info;

	max = 0;
	reset(ans, t_row, t_col);
	max = fill_nbr(t_row, t_col, ans);
	info = find_position(ans, t_row, t_col, max);
	ans = change_board(ans, info, max);
}

void	print_ans(int **ans, int t_row, int t_col, char *base)
{
	int		i;
	int		j;
	int		flag;

	flag = 1;
	i = -1;
	while (++i < t_row)
	{
		j = -1;
		while (++j < t_col)
		{
			if ((t_row == 1 || t_col == 1) && ans[i][j] == 0 && flag > 0)
			{
				write(1, &base[2], 1);
				flag--;
			}
			else
				write(1, &base[ans[i][j]], 1);
		}
		write(1, "\n", 1);
	}
	return ;
}
