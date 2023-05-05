/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:40:37 by minson            #+#    #+#             */
/*   Updated: 2023/04/27 16:37:52 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base_long(long nbr, char *base)
{
	int	i;

	i = base_count(base);
	if (base_check(base) != 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * (-1);
			ft_putnbr_base_long(nbr, base);
		}
		else if (nbr >= i)
		{
			ft_putnbr_base_long(nbr / i, base);
			ft_putnbr_base_long(nbr % i, base);
		}
		else
			ft_putchar(base[nbr]);
	}
	else
		return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	nb = nbr;
	ft_putnbr_base_long(nb, base);
}
