/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:32:27 by minson            #+#    #+#             */
/*   Updated: 2022/10/19 23:01:39 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_count(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

char	*ft_putnbr_base_long(long long nbr, char *base, char *str, int len)
{
	long long	i;
	char		tmp;

	tmp = 0;
	i = base_count(base);
	str[len] = '\0';
	len--;
	if (nbr == 0)
		str[0] = base[0];
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr != 0)
	{
		tmp = base[nbr % i];
		str[len] = tmp;
		nbr /= i;
		len--;
	}
	return (str);
}

int	ft_nbrlen(long long nbr, char *base)
{
	long long	i;
	long long	count;

	count = 0;
	i = base_count(base);
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		nbr /= i;
		count++;
	}
	return ((int)count);
}

char	*ft_putnbr_base(long long nbr, char *base, char *str, int len)
{
	ft_putnbr_base_long(nbr, base, str, len);
	return (str);
}
