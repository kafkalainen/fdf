/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:43:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 17:05:42 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"
#include "g42.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void		g42_mlx_draw_grid(t_data *img, t_map *map)
{
	g42_mod_pts(map, &g42_scale_point, 30);
	fdf_translate_coordinates(map);
	printf("%p\n", map);
	printf("%p\n", img);
	fdf_draw_wire(img, map, map->screen);
}
