/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:23:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 13:18:48 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_init_view(t_map *map, t_cam *cur)
{
	size_t	i;
	double	scale;

	i = 0;
	scale = (double)(WIN_WIDTH) / (double)(map->max_width);
	cur->dist = scale;
	while (i < map->pts)
	{
		map->proj[i] = map->coord[i];
		//printf("scale for point %ld, it has y of %f, and scale %f\n", i, map->proj[i].y, map->proj[i].c_scale);
		i++;
	}
	printf("scale for point %d, it has y of %f, and scale %f\n", 0, map->proj[0].y, map->proj[0].c_scale);
	printf("scale for point %d, it has y of %f, and scale %f\n", 1, map->proj[1].y, map->proj[1].c_scale);
	printf("scale for point %d, it has y of %f, and scale %f\n", 2, map->proj[2].y, map->proj[2].c_scale);
	g42_mod_pts(map, &g42_scale_point, scale);
	fdf_translate_coordinates(map, cur);
	return (0);
}
