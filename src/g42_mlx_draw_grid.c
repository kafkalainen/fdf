/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:43:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 08:17:50 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"
#include "g42.h"
#include <stdio.h>

void		g42_mlx_draw_grid(t_data *img, t_map *map)
{
	int		i;
	// int		u;
	// int		v;
	t_uv	uv[36];
	i = 0;
	while (i < 36)
	{
	//	g42_rotate_z_axis(&map->coord[i], 45.0f);
	//	g42_rotate_y_axis(&map->coord[i], 35.264f);
		g42_scale_point(&map->coord[i], 30);
		uv[i] = g42_2d_to_uv(map->coord[i]);
		i++;
	}
	printf("%p\n", map);
	printf("%p\n", img);
	i = 0;
	while (i < 36)
	{
		printf("Point %d: Screen x is %d, and y is %d\n", i, uv[i].u, uv[i].v);
		i++;
	}
	/*v = 0;
	while (v + 1 < 6)
	{
		u = 0;
		while (u + 1 < 6)
		{
			g42_mlx_draw_line_dda(img, &uv[u + v * 6], &uv[u + v * 6 + 1], 0x0000FF00);
			g42_mlx_draw_line_dda(img, &uv[u + v * 6], &uv[u + (v + 1) * 6], 0x0000FF00);
			// g42_mlx_draw_line_bre(img, &uv[u + v * 6], &uv[u + v * 6 + 1], 0x0000FF00);
			// g42_mlx_draw_line_bre(img, &uv[u + v * 6], &uv[u + (v + 1) * 6], 0x0000FF00);
		s	u++;
		}
		v++;
	}*/
	// g42_mlx_draw_line_dda(img, &uv[0 + 0 * map->width], &uv[0 + 0 * map->width + 1], 0x00FF0000);
	// g42_mlx_draw_line_dda(img, &uv[0 + 0 * map->width], &uv[1 + (0 + 1) * map->width], 0x00FF0000);
	// g42_mlx_draw_line_dda(img, &uv[1 + 0 * map->width], &uv[1 + 0 * map->width + 1], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[1 + 0 * map->width], &uv[1 + (0 + 1) * map->width], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[2 + 0 * map->width], &uv[2 + 0 * map->width + 1], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[2 + 0 * map->width], &uv[2 + (0 + 1) * map->width], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[3 + 0 * map->width], &uv[3 + 0 * map->width + 1], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[3 + 0 * map->width], &uv[3 + (0 + 1) * map->width], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[4 + 0 * map->width], &uv[4 + 0 * map->width + 1], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[4 + 0 * map->width], &uv[4 + (0 + 1) * map->width], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[5 + 0 * map->width], &uv[5 + 0 * map->width + 1], 0x000000FF);
	// g42_mlx_draw_line_dda(img, &uv[5 + 0 * map->width], &uv[5 + (0 + 1) * map->width], 0x000000FF);
	//g42_mlx_draw_line_dda(img, &uv[0 + 1 * map->width], &uv[0 + 1 * map->width + 1], 0x0000FF00);
	//g42_mlx_draw_line_dda(img, &uv[0 + 1 * map->width], &uv[0 + (1 + 1) * map->width], 0x0000FF00);
	// g42_mlx_draw_line_bre(img, &uv[0 + 0 * map->width], &uv[0 + 0 * map->width + 1], 0x00FF0000);
	// g42_mlx_draw_line_bre(img, &uv[0 + 0 * map->width], &uv[0 + (0 + 1) * map->width], 0x0000FF00);
	// g42_mlx_draw_line_bre(img, &uv[1 + 0 * map->width], &uv[1 + 0 * map->width + 1], 0x000000FF);
	// g42_mlx_draw_line_bre(img, &uv[1 + 0 * map->width], &uv[1 + (0 + 1) * map->width], 0x00FF0000);
	int x = 0;
	int y = 0;
	t_uv res;
	while (y < (int)map->height)
	{
		x = 0;
		while (x < (int)map->width)
		{
			res = uv[x + y * map->width];
			if (y != (int)map->height - 1)
			{
				// if (uv[x + (y + 1) * map->width].u == uv[x + y * map->width].u)
				// 	g42_mlx_draw_x_y_line(img, &res, &uv[x + (y + 1) * map->width], 0x00FF0000);
				// else
				g42_mlx_draw_line_bre(img, res, uv[x + (y + 1) * map->width], 0x00FF0000);
				// g42_mlx_draw_line_dda(img, &res, &uv[v + (u + 1) * map->width], 0x00FF0000);
			}
			if (x != (int)map->width - 1)
			{
				// if (uv[x + (y + 1) * map->width].v == uv[x + y * map->width].v)
				// 	g42_mlx_draw_x_y_line(img, &res, &uv[x + 1 + y * map->width], 0x00FF0000);
				// else
				g42_mlx_draw_line_bre(img, res, uv[x + 1 + y * map->width], 0x00FF0000);
				//g42_mlx_draw_line_dda(img, &res, &uv[v + 1 + u * map->width], 0x0000FF00);
			}
		x++;
		}
	y++;
	}
}
