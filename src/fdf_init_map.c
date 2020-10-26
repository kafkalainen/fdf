/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:23:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/26 13:39:54 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

/*
  0 0 0 0 0 0
  0 1 1 1 1 0
  0 1 2 2 1 0
  0 1 2 2 1 0
  0 1 1 1 1 0
  0 0 0 0 0 0
*/
int		fdf_init_map(t_map *map)
{
	size_t		i;
	size_t		z;
	t_vec3		coord;

	i = 0;
	z = 0;
	coord.x = 0;
	coord.z = 0;
	map->coord_amount = 36;
	map->height = 6;
	map->depth = 2;
	if (!(map->coord = (t_vec3*)malloc(sizeof(*map->coord) * map->coord_amount + 1)))
		return (0);
	if (!(map->screen = (t_uv*)malloc(sizeof(*(map->screen)) * map->coord_amount + 1)))
		return (0);
	if (!(map->width = (size_t*)malloc(sizeof(*(map->width)) * map->height + 1)))
		return (0);
	map->width[0] = 3;
	map->width[1] = 6;
	map->width[2] = 6;
	map->width[3] = 6;
	map->width[4] = 6;
	map->width[5] = 3;
	map->max_width = 6;
	while (coord.z < map->height)
	{
		coord.x = 0;
		while (coord.x < map->width[z])
		{
			map->coord[i].x = coord.x;
			map->coord[i].z = coord.z;
			map->coord[i].y = 0;
			coord.x++;
			i++;
		}
		if (map->width[z] < map->max_width)
			i += map->max_width - map->width[z];
		coord.z++;
		z++;
	}
	map->coord[7].y = 1;
	map->coord[8].y = 1;
	map->coord[9].y = 1;
	map->coord[10].y = 1;
	map->coord[13].y = 1;
	map->coord[14].y = 2;
	map->coord[15].y = 2;
	map->coord[16].y = 1;
	map->coord[19].y = 1;
	map->coord[20].y = 2;
	map->coord[21].y = 2;
	map->coord[22].y = 1;
	map->coord[25].y = 1;
	map->coord[26].y = 1;
	map->coord[27].y = 1;
	map->coord[28].y = 1;
	return (1);
}
