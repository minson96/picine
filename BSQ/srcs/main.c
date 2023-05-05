/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:09:17 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 11:03:26 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	set_idx(t_idx *idx, int argc)
{
	idx->i = 1;
	idx->argc = argc;
}

void	set_total(t_total *total)
{
	total->col = 0;
	total->row = 0;
}

void	print_answer(int **ans, t_total total, char *base, t_idx *idx)
{
	fill_ans(ans, total.row, total.col);
	print_ans(ans, total.row, total.col, base);
	free_ans(ans, total.row);
	if (idx->i != idx->argc - 1)
		write(1, "\n", 1);
	(idx->i)++;
}

void	print_error_and_index_up(t_idx *idx)
{
	write(1, "map error\n", 10);
	if (idx->i != idx->argc - 1)
		write(1, "\n", 1);
	(idx->i)++;
}

int	main(int argc, char *argv[])
{
	t_idx	idx;
	t_total	total;
	int		**ans;
	char	base[3];

	if (argc == 1)
		read_stdin(&argc, argv);
	set_idx(&idx, argc);
	while (idx.i < argc)
	{
		set_total(&total);
		if (read_info(argv[idx.i], &total.row, base))
		{
			if (read_map(argv[idx.i], &total.row, &total.col, base))
			{
				ans = make_ans(argv[idx.i], total.row, total.col, base);
				if (!ans)
					return (0);
				print_answer(ans, total, base, &idx);
				continue ;
			}
		}
		print_error_and_index_up(&idx);
	}
	return (0);
}
