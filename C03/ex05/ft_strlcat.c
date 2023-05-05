/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:18:23 by minson            #+#    #+#             */
/*   Updated: 2022/10/11 17:20:23 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = ft_strlen(dest);
	if (size > ft_strlen(dest))
	{
		while (dest[i])
			i++;
		while (src[j] && (j + i + 1 < size))
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
		return (k + ft_strlen(src));
	}
	else
		return (ft_strlen(src) + size);
}
