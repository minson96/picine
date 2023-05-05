/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:03:03 by minson            #+#    #+#             */
/*   Updated: 2022/10/06 12:30:25 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	str[3];

	str[0] = '0';
	while (str[0] <= '7')
	{
		str[1] = str[0] +1;
		while (str[1] <= '8')
		{
			str[2] = str[1] +1;
			while (str[2] <= '9')
			{
				write(1, str, 3);
				if (str[0] != '7')
					write(1, ", ", 2);
				str[2]++;
			}
			str[1]++;
		}
		str[0]++;
	}
}