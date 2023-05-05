/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:08:01 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 09:08:35 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	fill_base_and_total_row(char *str, int pos, int *total_row, char *base)
{
	int	i;
	int	j;

	i = pos + 1;
	j = 0;
	while (str[i] != '\n')
		base[j++] = str[i++];
	base[j] = '\0';
	i = 0;
	while (i <= pos)
		*total_row = *total_row * 10 + str[i++] - '0';
}

int	is_number(char *str, int i)
{
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	return (1);
}

int	is_duplicated(char *str, int *i)
{
	(*i)--;
	if (str[*i] == str[*i - 1]
		|| str[*i] == str[*i - 2]
		|| str[*i - 1] == str[*i - 2])
		return (1);
	else
		(*i) -= 3;
	return (0);
}

int	base_check(char *str, int *total_row, char *base)
{
	int	i;
	int	pos;

	i = 0;
	while (str[i] != '\n')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	if (i < 4)
		return (0);
	if (is_duplicated(str, &i))
		return (0);
	pos = i;
	while (i >= 0)
	{
		if (!is_number(str, i))
			return (0);
		i--;
	}
	fill_base_and_total_row(str, pos, total_row, base);
	return (1);
}
