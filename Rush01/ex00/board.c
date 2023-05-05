/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:24:17 by minson            #+#    #+#             */
/*   Updated: 2022/10/09 18:52:56 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

bool	check_valid_num(t_data *data, int y, int x);
bool	check_left(t_data *data, int y, int x);
bool	check_right(t_data *data, int y, int x);
bool	check_up(t_data *data, int y, int x);
bool	check_down(t_data *data, int y, int x);

int	check_board_valid(t_data *data, int y, int x)
{
	if (!check_valid_num(data, y, x))
		return (0);
	if (x == data->width - 1)
		if (!check_left(data, y, data->width - 1)
			|| !check_right(data, y, data->width - 1))
			return (0);
	if (y == data->width - 1)
		if (!check_up(data, data->width - 1, x)
			|| !check_down(data, data->width - 1, x))
			return (0);
	return (1);
}

int	fill_board(t_data *data, int y, int x)
{
	int	number;

	if (x == data->width)
	{
		y += 1;
		x = 0;
	}
	if (y == data->width)
		return (1);
	number = 1;
	while (number <= data->width)
	{
	data->grid[y][x] = number;
		if (check_board_valid(data, y, x)
			&& fill_board(data, y, x + 1))
			return (1);
		number++;
	}
	return (0);
}
