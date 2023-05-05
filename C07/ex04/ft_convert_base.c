/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:21:17 by minson            #+#    #+#             */
/*   Updated: 2022/10/19 21:06:58 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_putnbr_base(long long nbr, char *base, char *str, int len);
int		ft_nbrlen(long long nbr, char *base);
char	*ft_putnbr_base_long(long long nbr, char *base, char *str, int len);
int		base_count(char *base);

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
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
	return (i);
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

long long	ft_atoi_base(char *str, char *base)
{
	int			i;
	long long	sign;
	long long	res;

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
		res = res * base_check(base) + base_find(str[i], base);
		i++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*str;
	long long		deci;
	int				len;

	if (!(base_check(base_from) && base_check(base_to)))
		return (0);
	deci = ft_atoi_base(nbr, base_from);
	len = ft_nbrlen(deci, base_to);
	str = (char *)malloc(sizeof(char) * (len +1));
	if (str == 0)
		return (0);
	ft_putnbr_base(deci, base_to, str, len);
	return (str);
}
