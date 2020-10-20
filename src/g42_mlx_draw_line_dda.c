/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_line_dda.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:41:04 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 12:09:42 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "g42.h"

void		g42_mlx_draw_line_dda(t_data *img, t_uv *p0, t_uv *p1, int colour)
{
	t_vec3		delta;
	t_vec3		pixel;
	long int	pixels;

	delta.x = p1->u - p0->u;
	delta.y = p1->v - p0->v;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= pixels;
	delta.y /= pixels;
	pixel.x = p0->u;
	pixel.y = p0->v;
	while (pixels)
	{
		g42_mlx_pixel_put(img, pixel.x, pixel.y, colour);
		pixel.x += delta.x;
		pixel.y += delta.y;
		--pixels;
	}
}