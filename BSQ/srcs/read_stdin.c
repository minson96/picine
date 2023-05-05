/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:09:50 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 10:31:04 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	open_stdin(void)
{
	int		fd;
	char	buf[5000];

	fd = open("map.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (0);
	while (read(0, buf, 1))
		write(fd, buf, 1);
	close(fd);
	return (1);
}

void	read_stdin(int *argc, char *argv[])
{
	if (open_stdin() == 1)
	{
		*argc = 2;
		argv[1] = "map.txt";
	}
}