/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:11 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 09:06:30 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	reset(int **ans, int t_row, int t_col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < t_row)
	{
		if (ans[i][0] == -1)
			ans[i][0] = 1;
		i++;
	}
	while (j < t_col)
	{
		if (ans[0][j] == -1)
			ans[0][j] = 1;
		j++;
	}
	return ;
}

int	min(int n1, int n2, int n3)
{
	int	i;

	i = 2147483647;
	if (i > n1)
		i = n1;
	if (i > n2)
		i = n2;
	if (i > n3)
		i = n3;
	return (i);
}

int	fill_nbr(int t_row, int t_col, int **ans)
{
	int	i;
	int	j;
	int	max;

	i = 1;
	max = 0;
	while (i < t_row)
	{
		j = 1;
		while (j < t_col)
		{
			if (ans[i][j] == 0)
				j++;
			else
			{
				ans[i][j] = min(ans[i][j - 1], ans[i - 1][j],
						ans[i - 1][j - 1]) + 1;
				if (ans[i][j] > max)
					max = ans[i][j];
				j++;
			}
		}
		i++;
	}
	return (max);
}
