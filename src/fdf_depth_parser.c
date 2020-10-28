/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_depth_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:40:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/26 18:58:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"
#include "fdf.h"

double		fdf_depth_parser(char *elem)
{
	size_t	len;
	char	*start;
	int		nb;
	int		nb_end;
	double	db;
	char	legal[17];

	ft_strcpy(legal, "0123456789ABCDEF");
	start = elem;
	len = ft_strlen(elem);
	db = 0.0;
	if (len > 3 && elem[0] == '0' && ft_toupper(elem[1]) == 'X')
	{
		if (fdf_check_valid_depth(elem + 2, legal) == INVALID_CHARACTERS)
			return (EXIT_FAILURE);
		db = ft_atoi_base(elem + 2, 16);
	}
	if (len > 4 && ft_isdigit(elem[0]))
	{
		while (*elem != '\0' && ft_isdigit(*elem))
			elem++;
		if (*elem == ',')
		{
			nb = ft_atoi_base(start, 10);
				elem++;
			if (*elem == '0' && ft_toupper(*(elem + 1)) == 'X')
				nb_end = ft_atoi_base(elem + 2, 16);
			else
				nb_end = ft_atoi_base(elem + 2, 10);
			db = fdf_double_parser(nb, nb_end);
		}
	}
	else
		db = (double)(ft_atoi_base(elem, 10));
	return (db);
}
