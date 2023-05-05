/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:26:57 by minson            #+#    #+#             */
/*   Updated: 2022/10/06 18:36:11 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recur(char *arr, int n, int dep, int nb)
{
	if (dep == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	while (nb <= '9')
	{
		arr[dep] = nb;
		ft_recur(arr, n, dep +1, nb +1);
		nb++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	char	arr[9];

	ft_recur(arr, n, 0, '0');
}
