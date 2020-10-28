/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate_coordinates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:26:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 14:39:09 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_uv	*fdf_translate_coordinates(t_map *map, t_cam *cam)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return (NULL);
	while (i < map->coord_amount)
	{
		map->screen[i] = g42_2d_to_uv(map->proj[i], map, cam);
		i++;
	}
	return (map->screen);
}
