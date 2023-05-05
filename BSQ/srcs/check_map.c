/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:05:02 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 11:04:48 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	if (c == '\n')
		return (1);
	while (i < 2)
		if (c == base[i++])
			return (1);
	return (0);
}

int	map_check(char c, int row, int col, char *base)
{
	if (row == 0 && col == 0 && c == '\n')
		return (0);
	if (!is_in_base(c, base))
		return (0);
	return (1);
}
