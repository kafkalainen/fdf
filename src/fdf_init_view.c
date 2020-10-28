/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_view.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:23:57 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 15:15:54 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_init_view(t_map *map, t_cam *cur)
{
	size_t	i;
	double	scale;

	i = 0;
	scale = (double)(WIN_WIDTH) / (double)(map->max_width);
	cur->dist = scale;
	while (i < map->coord_amount)
	{
		map->proj[i] = map->coord[i];
		i++;
	}
	g42_mod_pts(map, &g42_scale_point, scale);
	fdf_translate_coordinates(map, cur);
	return (0);
}
