/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:27:43 by minson            #+#    #+#             */
/*   Updated: 2022/10/09 18:54:15 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	error_message(void);

void	initialize_board(int *board_line, int width)
{
	int	idx;

	idx = 0;
	while (idx < width)
	{
		board_line[idx] = 0;
		idx++;
	}
}

int	*make_border(char *input_nums, int input_len)
{
	int	*border;
	int	input_i;
	int	border_i;

	input_i = 0;
	border_i = 0;
	border = (int *) malloc(sizeof(int) * input_len);
	while (input_nums[input_i])
	{
		border[border_i++] = input_nums[input_i] - '0';
		input_i += 2;
	}
	return (border);
}

int	get_border_length(char *input_nums)
{
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	while (input_nums[idx])
	{
		if (idx % 2 == 0)
		{
			if ('1' <= input_nums[idx] && input_nums[idx] <= '9')
				count++;
			else
				return (-1);
		}
		else
		{
			if (input_nums[idx] != ' ')
				return (-1);
		}
		idx++;
	}
	if (count > 36 || (idx + 1) % 4 != 0 || count == 0 || count % 4 != 0)
		return (-1);
	return (count);
}

int	**make_grid(int width)
{
	int	**grid;
	int	idx;

	idx = 0;
	grid = (int **) malloc(sizeof(int *) * width);
	if (grid == NULL)
	{
		error_message();
		return (NULL);
	}
	while (idx < width)
	{
		grid[idx] = (int *) malloc(sizeof(int) * width);
		initialize_board(grid[idx], width);
		idx++;
	}
	return (grid);
}

int	initialize_struct(t_data *data, char *input_nums)
{
	int	input_len;

	input_len = get_border_length(input_nums);
	if (input_len == -1)
		return (0);
	data->width = input_len / 4;
	data->border = make_border(input_nums, input_len);
	data->up = data->border;
	data->down = data->border + data->width * 1;
	data->left = data->border + data->width * 2;
	data->right = data->border + data->width * 3;
	data->grid = make_grid(input_len);
	return (1);
}
