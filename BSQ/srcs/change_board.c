/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:04:43 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 09:04:51 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	*find_position(int **ans, int t_row, int t_col, int max)
{
	int	*info;

	info = (int *)malloc(sizeof(int) * 6);
	info[0] = 0;
	while (info[0] < t_row)
	{
		info[1] = 0;
		while (info[1] < t_col)
		{
			if (ans[info[0]][info[1]] == max)
			{
				info[2] = info[0];
				info[3] = info[1];
				break ;
			}
			info[1]++;
		}
		if (ans[info[0]][info[1]] == max)
			break ;
		info[0]++;
	}
	info[4] = t_row;
	info[5] = t_col;
	return (info);
}

int	**change_board(int **ans, int *info, int max)
{
	info[0] = 0;
	while (info[0] < info[4])
	{
		info[1] = 0;
		while (info[1] < info[5])
		{
			if ((info[0] > info[2] - max && info[0] < info[2] + 1)
				&& (info[1] > info[3] - max && info[1] < info[3] + 1))
				ans[info[0]][info[1]] = 2;
			else if (ans[info[0]][info[1]] == 0)
				ans[info[0]][info[1]] = 1;
			else
				ans[info[0]][info[1]] = 0;
			info[1]++;
		}
		info[0]++;
	}
	free(info);
	return (ans);
}
