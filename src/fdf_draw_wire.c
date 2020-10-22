/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_wire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:20:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 17:48:34 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_draw_wire(t_data *data, t_map *map, t_uv *coord)
{
	size_t	x;
	size_t	y;
	t_uv	res;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			res = coord[fdf_idx(x, y, map)];
			if (y != map->height - 1)
			{
				g42_mlx_draw_x_y_line(data, res, coord[fdf_idx(x, y + 1, map)], 0x00FF0000);
				/*g42_mlx_draw_line_dda(data, res, coord[fdf_idx(x + 1, y, map)], 0x00FF0000);*/
				g42_mlx_draw_line_bre(data, res, coord[fdf_idx(x, y + 1, map)], 0x00FF0000);
				// g42_mlx_draw_line_wu(data, res, coord[fdf_idx(x, y + 1, map)], 0x00FF0000);
			}
			if (x != map->width - 1)
			{
				g42_mlx_draw_x_y_line(data, res, coord[fdf_idx(x + 1, y, map)], 0x00FF0000);
				/*g42_mlx_draw_line_dda(data, res, coord[fdf_idx(x + 1, y, map)], 0x00FF0000);*/
				g42_mlx_draw_line_bre(data, res, coord[fdf_idx(x + 1, y, map)], 0x00FF0000);
				// g42_mlx_draw_line_wu(data, res, coord[fdf_idx(x, y + 1, map)], 0x00FF0000);
			}
		x++;
		}
	y++;
	}
}
