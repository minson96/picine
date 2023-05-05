/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:05:35 by minson            #+#    #+#             */
/*   Updated: 2022/10/20 18:16:24 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < length)
	{
		if ((*f)(tab[i], tab[i +1]) < 0)
		{
			if (flag == 1)
				return (0);
			flag = -1;
		}
		if ((*f)(tab[i], tab[i +1]) > 0)
		{
			if (flag == -1)
				return (0);
			flag = 1;
		}
		i++;
	}
	return (1);
}
