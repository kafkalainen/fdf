/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_colour_scale.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:03:12 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 13:09:39 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

int		fdf_count_colour_scale(t_map *map)
{
	size_t	i;
	double	minmax_dist;
	double	c_dist;

	i = 0;
	minmax_dist = (double)((map->max_depth - map->min_depth));
	while (i < map->pts)
	{
		c_dist = (double)(map->coord[i].y - map->min_depth);
		map->coord[i].c_scale = (double)(c_dist / minmax_dist);
		i++;
	}
	return (0);
}
