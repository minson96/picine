/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:23:27 by minson            #+#    #+#             */
/*   Updated: 2022/10/09 18:55:55 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	*border;
	int	*up;
	int	*down;
	int	*left;
	int	*right;
	int	**grid;
	int	width;

}	t_data;
#endif