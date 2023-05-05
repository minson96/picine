/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:06:46 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 09:07:14 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_info(char *filename, int *total_row, char *base)
{
	int		fd;
	char	info[20];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!read(fd, info, 20))
	{
		close(fd);
		return (0);
	}
	if (base_check(info, total_row, base))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	read_map2(int fd, int *total_col, char *base, int *row)
{
	int		col;
	char	buf[30];

	col = 0;
	while (read(fd, buf, 1))
	{
		if (!map_check(*buf, *row, col, base))
			return (0);
		if (*buf != '\n')
			col++;
		if (*buf == '\n')
		{
			if (*total_col != col && *row > 0)
				return (0);
			(*row)++;
			*total_col = col;
			col = 0;
		}
	}
	return (1);
}

int	open_and_offset(char *filename)
{
	int		fd;
	char	buf[30];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		read(fd, buf, 1);
		if (*buf == '\n')
			break ;
	}
	return (fd);
}

int	read_map(char *filename, int *total_row, int *total_col, char *base)
{
	int		fd;
	int		row;

	fd = open_and_offset(filename);
	row = 0;
	if (read_map2(fd, total_col, base, &row) == 0)
	{
		close(fd);
		return (0);
	}
	if (row == 0 || *total_row != row)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
