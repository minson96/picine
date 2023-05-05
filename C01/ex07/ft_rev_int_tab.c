/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:22:53 by minson            #+#    #+#             */
/*   Updated: 2022/10/03 12:08:06 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	mid;
	int	i;
	int	tmp;

	i = 0;
	mid = size / 2;
	while (mid > 0)
	{
		tmp = tab[i];
		tab[i] = tab[size -1];
		tab[size -1] = tmp;
		size--;
		i++;
		mid--;
	}
}
