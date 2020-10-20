/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_line_bre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 10:47:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/19 14:28:04 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "g42.h"

void		g42_mlx_draw_line_bre(t_data *img, t_uv *p0, t_uv *p1, int colour);
/*{
	t_vec3	current;
	t_vec3	delta;
	t_vec3	sign;
	int		err;
	int		e2;

	delta.x = abs(p1->u - p0->u);
	delta.y = -abs(p1->v - p0->v);
	sign.x = p0->u < p1->u ? 1 : -1;
	sign.y = p0->v < p1->v ? 1 : -1;
	err = delta.x + delta.y;
	current.x = p0->u;
	current.y = p0->v;
	while (current.x != p1->u && current.y != p1->v)
	{
		g42_mlx_pixel_put(img, current.x, current.y, colour);
		e2 = 2 * err;
		if (e2 >= delta.y)
		{
			err += delta.y;
			current.x += sign.x;
		}
		if (e2 <= delta.x)
		{
			err += delta.x;
			current.y += sign.y;
		}
	}
}*/
