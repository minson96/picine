/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:38:55 by minson            #+#    #+#             */
/*   Updated: 2022/10/19 16:17:55 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	ran;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	ran = max - min;
	*range = (int *)malloc(sizeof(int) * ran);
	if (*range == 0)
		return (0);
	while (ran > i)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	range[0][i] = 0;
	return (ran);
}
