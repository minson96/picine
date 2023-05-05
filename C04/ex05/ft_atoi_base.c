/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:15:32 by minson            #+#    #+#             */
/*   Updated: 2022/10/12 20:42:09 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_count(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base_count(base) == 0 || base_count(base) == 1)
		return (0);
	while (base[i])
	{
		j = i +1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+' || (base[i] == 32
				&& (base[i] >= 9 && base[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

int	base_find(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	base_change(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (base_find(str[i], base) != (-1))
	{
		res = res * base_count(base) + base_find(str[i], base);
		i++;
	}
	return (res * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	if (base_check(base) != 0)
	{
		return (base_change(str, base));
	}
	return (0);
}
