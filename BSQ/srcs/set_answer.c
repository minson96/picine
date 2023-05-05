/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:07:38 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 09:07:53 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	**make_ans2(int **ans, int fd, char *base)
{
	int		row;
	int		col;
	char	buf[30];

	row = 0;
	col = 0;
	while (read(fd, buf, 1))
	{
		if (*buf == base[0])
			ans[row][col] = -1;
		else if (*buf == base[1])
			ans[row][col] = 0;
		else
		{
			row++;
			col = -1;
		}
		col++;
	}
	close(fd);
	return (ans);
}

int	**make_ans(char *filename, int total_row, int total_col, char *base)
{
	int		fd;
	int		i;
	int		**ans;
	char	buf[30];

	ans = (int **)malloc(sizeof(int *) * total_row);
	if (!ans)
		return (0);
	i = -1;
	while (++i < total_row)
	{
		ans[i] = (int *)malloc(sizeof(int) * total_col);
		if (!ans[i])
			return (0);
	}
	fd = open(filename, O_RDONLY);
	while (1)
	{
		read(fd, buf, 1);
		if (*buf == '\n')
			break ;
	}
	return (make_ans2(ans, fd, base));
}

void	free_ans(int **ans, int total_row)
{
	int	i;

	i = -1;
	while (++i < total_row)
		free(ans[i]);
	free(ans);
}
