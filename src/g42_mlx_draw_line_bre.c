/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_line_bre.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 10:47:01 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 08:17:07 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "g42.h"

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
