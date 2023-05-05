/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:27:52 by minson            #+#    #+#             */
/*   Updated: 2022/10/09 17:27:52 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_valid_num(t_data *data, int y, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (data->grid[y][i] == data->grid[y][x])
			return (0);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (data->grid[i][x] == data->grid[y][x])
			return (0);
		i++;
	}
	return (1);
}

int	check_left(t_data *data, int y, int x)
{
	int	max;
	int	cnt;
	int	x_;

	max = 0;
	cnt = 0;
	x_ = 0;
	while (x_ <= x)
	{
		if (max < data->grid[y][x_])
		{
			max = data->grid[y][x_];
			cnt++;
		}
		x_++;
	}
	if (cnt != *(data->left + y))
		return (0);
	return (1);
}

int	check_right(t_data *data, int y, int x)
{
	int	max;
	int	x_;
	int	cnt;

	max = 0;
	cnt = 0;
	x_ = x;
	while (x_ >= 0)
	{
		if (max < data->grid[y][x_])
		{
			max = data->grid[y][x_];
			cnt++;
		}
		x_--;
	}
	if (cnt != *(data->right + y))
		return (0);
	return (1);
}

int	check_up(t_data *data, int y, int x)
{
	int	max;
	int	y_;
	int	cnt;

	max = 0;
	cnt = 0;
	y_ = 0;
	while (y_ <= y)
	{
		if (max < data->grid[y_][x])
		{
			max = data->grid[y_][x];
			cnt++;
		}
		y_++;
	}
	if (cnt != *(data->up + x))
		return (0);
	return (1);
}

int	check_down(t_data *data, int y, int x)
{
	int	max;
	int	y_;
	int	cnt;

	max = 0;
	cnt = 0;
	y_ = y;
	while (y_ >= 0)
	{
		if (max < data->grid[y_][x])
		{
			max = data->grid[y_][x];
			cnt++;
		}
		y_--;
	}
	if (cnt != *(data->down + x))
		return (0);
	return (1);
}
