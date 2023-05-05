/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 01:24:57 by minson            #+#    #+#             */
/*   Updated: 2022/10/19 20:32:20 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*arr;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	range = max - min;
	arr = (int *)malloc(sizeof(int) * range);
	if (arr == 0)
		return (0);
	while (range > i)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
