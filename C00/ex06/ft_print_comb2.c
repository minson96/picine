/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:33:18 by minson            #+#    #+#             */
/*   Updated: 2022/10/03 21:46:09 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putin(int a)
{
	char	b;
	char	c;

	if (a < 10)
	{
		b = a + '0';
		write(1, "0", 1);
		write(1, &b, 1);
	}
	else
	{
		b = a % 10 + '0';
		c = a / 10 + '0';
		write(1, &c, 1);
		write(1, &b, 1);
	}
}

void	ft_print_comb2(void)
{
	int	str1;
	int	str2;

	str1 = 0;
	while (str1 <= 98)
	{
		str2 = str1 +1;
		while (str2 <= 99)
		{
			ft_putin(str1);
			write(1, " ", 1);
			ft_putin(str2);
			if (!(str1 == 98 && str2 == 99))
				write(1, ", ", 2);
			str2++;
		}
		str1++;
	}
}
