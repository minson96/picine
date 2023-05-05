/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:37:51 by minson            #+#    #+#             */
/*   Updated: 2022/10/05 10:49:56 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	sign;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 0 && str[i] <= 31) || str[i] == 127))
			sign = 1;
		else
		{
			sign = 0;
			return (sign);
		}
		i++;
	}
	if (i == 0)
		return (1);
	return (sign);
}
