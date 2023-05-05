/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:24:36 by minson            #+#    #+#             */
/*   Updated: 2022/10/09 18:55:35 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	initialize_struct(t_data *data, char *input_nums);
int	fill_board(t_data *data, int y, int x);

int	error_message(void)
{
	write(2, "error\n", 6);
	return (0);
}

int	print_board(t_data *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->width)
		{
			c = data->grid[i][j] + '0';
			write(1, &c, 1);
			if (!(j == data->width - 1))
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 2)
		return (error_message());
	if (!initialize_struct(&data, argv[1]))
		return (error_message());
	if (fill_board(&data, 0, 0))
		print_board(&data);
	else
		return (error_message());
	free(data.border);
	i = 0;
	while (i++ < data.width)
		free(data.grid[i]);
	free(data.grid);
	return (0);
}
