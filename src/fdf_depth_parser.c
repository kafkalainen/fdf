/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_depth_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:40:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/31 11:09:40 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"
#include "fdf.h"

static double	fdf_combined_format(char *elem)
{
	double		comb_db;
	char		*start;
	int			nb;
	int			nb_end;

	comb_db = 0.0;
	start = elem;
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
		comb_db = fdf_double_parser(nb, nb_end);
	}
	return (comb_db);
}

double			fdf_depth_parser(t_map *map, char *elem)
{
	size_t			len;
	double			db;

	len = ft_strlen(elem);
	db = 0.0;
	if (len > 4 && elem[0] == '0' && ft_toupper(elem[1]) == 'X')
		db = ft_atoi_base(elem + 2, 16);
	else if (len > 4 && ft_isdigit(elem[0]))
		db = fdf_combined_format(elem);
	else if (len > 0)
		db = (double)(ft_atoi_base(elem, 10));
	else
		db = 0.0;
	if (db < map->min_depth)
		map->min_depth = db;
	if (db > map->max_depth)
		map->max_depth = db;
	return (db);
}
