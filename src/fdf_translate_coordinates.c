/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:26:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 13:16:51 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

t_uv	*fdf_translate_coordinates(t_map *map, t_cam *cam)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return (NULL);
	while (i < map->pts)
	{
		printf("Coord c_scale is %f\n", map->proj[i].c_scale);
		map->screen[i] = g42_2d_to_uv(&map->proj[i], map, cam);
		i++;
	}
	return (map->screen);
}
