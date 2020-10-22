/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_line_bre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 10:47:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 18:08:22 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "g42.h"
#include <stdint.h>

void		g42_mlx_draw_line_bre(t_data *data, t_uv p0, t_uv p1, int colour)
{
	t_uv	delta;
	t_uv	sign;
	int		err;
	int		e2;

	delta.u = ft_abs(p1.u - p0.u);
	delta.v = ft_abs(p1.v - p0.v);
	sign.u = p0.u < p1.u ? 1 : -1;
	sign.v = p0.v < p1.v ? 1 : -1;
	err = delta.u > delta.v ? delta.u : -delta.v / 2;
	while (p0.u != p1.u && p0.v != p1.v)
	{
		g42_mlx_pixel_put(data, p0.u, p0.v, colour);
		e2 = err;
		if (e2 > -delta.u)
		{
			err -= delta.v;
			p0.u += sign.u;
		}
		if (e2 < delta.u)
		{
			err += delta.u;
			p0.v += sign.v;
		}
	}
}

/*void		g42_mlx_draw_line_bre(t_data *data, t_uv p0, t_uv p1, int colour)
{
	t_uv f;
	t_uv g;
	int x;
	int32_t m=((int32_t)(p1.v-p0.v) << 16)/(p1.u-p0.u);

	f.v = p1.v << 16;
	for (x = p0.u;x<=p1.u;x++,f.u+=m)
	{
		g = f;
		g.u+=32767;
		put_pixel(x,g.hi,color);
		g42_mlx_pixel_put(data, p0.u, p0.v, colour);
	}
}*/
