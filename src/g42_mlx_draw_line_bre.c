/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_line_bre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 10:47:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/23 13:37:18 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "g42.h"

void		g42_mlx_draw_line_bre(t_data *data, t_uv p0, t_uv p1, int colour)
{
	t_vec3	delta;
	t_vec3	sign;
	double	err;
	double	e2;

	delta.x = (double)ft_abs(p1.u - p0.u);
	delta.y = (double)ft_abs(p1.v - p0.v);
	sign.x = p0.u < p1.u ? 1 : -1;
	sign.y = p0.v < p1.v ? 1 : -1;
	err = (double)(delta.x > delta.y ? delta.x : -delta.y / 2);
	while (p0.u != p1.u || p0.v != p1.v)
	{
		g42_mlx_pixel_put(data, p0.u, p0.v, colour);
		e2 = err;
		if (e2 > -delta.x)
		{
			err -= delta.y;
			p0.u += sign.x;
		}
		if (e2 < delta.x)
		{
			err += delta.x;
			p0.v += sign.y;
		}
	}
}
