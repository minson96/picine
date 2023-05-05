/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:25:11 by minson            #+#    #+#             */
/*   Updated: 2022/10/19 20:57:19 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_totlen(int size, char **strs, char *sep)
{
	int	i;
	int	sep_len;
	int	tot_len;

	i = 0;
	tot_len = 0;
	sep_len = ft_strlen3(sep);
	while (size > i)
	{
		if (i != 0)
			tot_len += sep_len;
		tot_len += ft_strlen3(strs[i]);
		i++;
	}
	return (tot_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_totlen(size, strs, sep);
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	str = (char *)malloc(sizeof(char) * (len +1));
	if (str == 0)
		return (0);
	str[0] = 0;
	i = 0;
	while (size > i)
	{
		if (i != 0)
			ft_strcat(str, sep);
		ft_strcat(str, strs[i]);
		i++;
	}
	return (str);
}
