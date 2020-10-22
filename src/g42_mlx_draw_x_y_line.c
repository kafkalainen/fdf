/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_x_y_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:15:11 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 09:02:21 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void	g42_mlx_draw_x_y_line(t_data *data, t_uv p0, t_uv p1, int colour)
{
	t_uv min;
	t_uv max;

	min = p0;
	max = p1;
	if (p0.u == p1.u)
	{
		min.v = p0.v < p1.v ? p0.v : p1.v;
		max.v = p0.v > p1.v ? p0.v : p1.v;
		while (min.v < max.v)
		{
			g42_mlx_pixel_put(data, min.u, min.v, colour);
			min.v++;
		}
	}
	if (p0.v == p1.v)
	{
		min.u = p0.u < p1.u ? p0.u : p1.u;
		max.u = p0.u > p1.u ? p0.u : p1.u;
		while (min.u < max.u)
		{
			g42_mlx_pixel_put(data, min.u, min.v, colour);
			min.u++;
		}
	}
}
