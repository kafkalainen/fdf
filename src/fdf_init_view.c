/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:23:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 15:43:41 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_init_view(t_map *map, t_cam *cur)
{
	size_t	i;
	double	scale_w;
	double	scale_h;
	double	scale;

	i = 0;
	scale_w = (double)(WIN_WIDTH) / (double)(map->max_width);
	scale_h = (double)(WIN_HEIGHT - MENU_HEIGHT) / (double)(map->height);
	scale = scale_h < scale_w ? scale_h : scale_w;
	cur->dist = scale;
	while (i < map->pts)
	{
		map->proj[i] = map->coord[i];
		i++;
	}
	fdf_count_colour_scale(map);
	g42_mod_pts(map, &g42_scale_point, scale);
	fdf_translate_coordinates(map, cur);
	return (0);
}
