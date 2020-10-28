/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_2d_to_uv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:03:37 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/28 15:06:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uv	g42_2d_to_uv(t_vec3 coord, t_map *map, t_cam *cam)
{
	t_uv	screen_coord;

	screen_coord.u = (int)(WIN_WIDTH / 2 + coord.x);
	screen_coord.u -= (int)((map->max_width - 1) * cam->dist / 2);
	screen_coord.v = (int)(WIN_HEIGHT / 2 - coord.y + MENU_HEIGHT);
	screen_coord.v += (int)((map->height - 1) * cam->dist / 2);
	screen_coord.colour = coord.colour;
	return (screen_coord);
}
