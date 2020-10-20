/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:43:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 12:15:21 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"
#include "g42.h"
#include <stdio.h>

void		g42_mlx_draw_grid(t_data *img, t_map *map)
{
	int		i;
	int		u;
	int		v;
	t_vec2	coord[36];
	t_uv	uv[36];

	i = 0;
	while (i < 36)
	{
		if (map->coord[i].z > 0)
		{
			coord[i] = g42_2d_transformation(&map->coord[i]);
			coord[i] = g42_2d_to_ndc(coord[i]);
			uv[i] = g42_ndc_to_raster_space(coord[i]);
		}
		i++;
	}
	i = 0;
	printf("%p\n", img);
	while (i < 36)
	{
		printf("Screen x is %f, and y is %f\n", uv[i].u, uv[i].v);
		i++;
	}
	v = 0;
	while (v + 1 < 6)
	{
		u = 0;
		while (u + 1 < 6)
		{
			g42_mlx_draw_line_dda(img, &uv[u + v * 6], &uv[u + v * 6 + 1], 0x0000FF00);
			g42_mlx_draw_line_dda(img, &uv[u + v * 6], &uv[u + (v + 1) * 6], 0x0000FF00);
			u++;
		}
		v++;
	}
}
