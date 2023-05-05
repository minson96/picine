/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:11:34 by minson            #+#    #+#             */
/*   Updated: 2022/10/03 14:00:18 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *tab1, int *tab2)
{
	int	tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	size2;

	i = 0;
	while (size > i)
	{
		j = i +1;
		size2 = size -1;
		while (size2 >= j)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
