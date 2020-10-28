/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_wire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:20:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/28 15:02:40 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		fdf_draw_wire(t_data *data, t_map *map, t_uv *coord)
{
	size_t	x;
	size_t	z;
	t_uv	res;

	z = 0;
	fdf_draw_background(data);
	while (z < map->height)
	{
		x = 0;
		while (x < map->width[z])
		{
			res = coord[fdf_idx(x, z, map)];
			if (z < map->height - 1 && x < map->width[z + 1])
				fdf_draw_line(data, res, coord[fdf_idx(x, z + 1, map)], 0x00FF0000);
			if (x < map->width[z] - 1)
				fdf_draw_line(data, res, coord[fdf_idx(x + 1, z, map)], 0x00FF0000);
		//printf("It is Z %ld and X %ld\n", z, x);
		//printf("Index is %ld\n", fdf_idx(x, z, map));
		x++;
		}
	z++;
	}
	fdf_draw_menu(data, 0xff5ca08e);
}

//printf("Z[coord %ld]: Drawing from x %d y %d to x %d y %d coordinate\n", fdf_idx(x, z + 1, map), res.u, res.v, coord[fdf_idx(x, z + 1, map)].u, coord[fdf_idx(x, z + 1, map)].v);
// printf("X[coord %ld]: Drawing from x %d y %d to x %d y %d coordinate\n", fdf_idx(x + 1, z, map), res.u, res.v, coord[fdf_idx(x + 1, z, map)].u, coord[fdf_idx(x + 1, z, map)].v);
