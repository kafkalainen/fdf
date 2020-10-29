/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colour_scale_coord.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:59:02 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 08:50:12 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "fdf.h"

int		fdf_colour_scale_coord(t_map *map, t_vec3 *proj, t_cam *cur)
{
	double		div;
	double		scaler;
	int			min_colour;
	size_t		i;
	t_colour	trgb;

	scaler = map->max_depth - map->min_depth;
	min_colour = 0x00000000;
	trgb = g42_hex_to_trgb(cur->colour);
	i = 0;
	while (i < map->pts)
	{
		div = (double)((map->coord[i].y - map->min_depth) / scaler);
		trgb.r = (int)(div * trgb.r);
		trgb.g = (int)(div * trgb.g);
		trgb.b = (int)(div * trgb.b);

	}

}
