/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:35:49 by minson            #+#    #+#             */
/*   Updated: 2022/10/19 16:47:08 by minson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	set_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (set_check(str[i], charset) == 0 && str[i])
			i++;
		if (set_check(str[i], charset) == 1 && str[i])
			count++;
		while (set_check(str[i], charset) == 1 && str[i])
			i++;
	}
	return (count);
}

char	*word_check(char *str, char *charset, int pos)
{
	int		i;
	int		j;
	int		count;
	char	*word;

	i = pos;
	j = 0;
	count = 0;
	while (set_check(str[i], charset) == 1 && str[i])
	{
		count++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (count +1));
	if (word == 0)
		return (0);
	i = pos;
	while (set_check(str[i], charset) == 1 && str[i])
	{
		word[j] = str[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		wd_count;
	char	**str_arr;

	i = 0;
	j = 0;
	wd_count = word_count(str, charset);
	str_arr = (char **)malloc(sizeof(char *) * (wd_count +1));
	if (str_arr == 0)
		return (0);
	while (str[i])
	{
		while (set_check(str[i], charset) == 0 && str[i])
			i++;
		if (set_check(str[i], charset) == 1 && str[i])
		{
			str_arr[j] = word_check(str, charset, i);
			j++;
		}
		while (set_check(str[i], charset) == 1 && str[i])
			i++;
	}
	str_arr[j] = 0;
	return (str_arr);
}
