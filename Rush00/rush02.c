/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:53:15 by minson            #+#    #+#             */
/*   Updated: 2022/10/01 19:25:21 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char l, char m, char r, int count);

void	rush(int row, int col)
{
	int	c;

	c = 1;
	while (col >= c )
	{
		if (c == 1)
			ft_putchar('o', '-', 'o', row);
		else if (c < col)
			ft_putchar('|', ' ', '|', row);
		else if (c == col)
			ft_putchar('o', '-', 'o', row);
		c++;
	}
}
