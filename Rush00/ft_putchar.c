/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 09:53:32 by minson            #+#    #+#             */
/*   Updated: 2022/10/01 19:13:10 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char l, char m, char r, int count)
{
	int	mc;
	
	if (count > 2)
		mc = count -2;
	if (count >= 1)
		write(1, &l, 1);
	if (count > 2)
	{
		while (mc > 0)
		{
			write(1, &m, 1);
			mc--;
			count--;
		}	
	}
	if (count == 2)
	{
		write(1, &r, 1);
		write(1, "\n", 1);
	}
}
