/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_2d_to_uv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:03:37 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 13:15:47 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

t_uv	g42_2d_to_uv(t_vec3 *coord, t_map *map, t_cam *cam)
{
	t_uv	screen_coord;

	screen_coord.u = (int)(WIN_WIDTH / 2 + coord->x);
	screen_coord.u -= (int)((map->max_width - 1) * cam->dist / 2);
	screen_coord.v = (int)(MENU_HEIGHT + (WIN_HEIGHT - MENU_HEIGHT) / 2);
	screen_coord.v += (int)((map->height - 1) * cam->dist / 4) - coord->y;
	screen_coord.s_scale = coord->c_scale;
	// printf("Coord c_scale is %f\n", coord.c_scale);
	printf("Coord c_scale is %f\n", coord->c_scale);
	printf("Screen_c_scale is %f\n", screen_coord.s_scale);
	return (screen_coord);
}
