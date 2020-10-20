/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_ndc_to_raster_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:54:02 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 12:23:09 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

t_uv	g42_ndc_to_raster_space(t_vec2 ndc)
{
	t_uv	raster_space;

	raster_space.u = (int)(ndc.x * WIN_WIDTH);
    raster_space.v = (int)((1 - ndc.y) * WIN_HEIGHT);
	return (raster_space);
}
