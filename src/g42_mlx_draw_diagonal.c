/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_diagonal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:14:17 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 18:38:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "../libft/libft.h"

void	g42_mlx_draw_diagonal(t_data *data, t_uv p0, t_uv p1, int colour)
{
	t_uv	delta;
	t_uv	max;
	t_uv	min;

	delta.u = ft_abs(p1.u - p0.u);
	delta.v = ft_abs(p1.v - p0.v);
	min.v = p0.v < p1.v ? p0.v : p1.v;
	max.v = p0.v > p1.v ? p0.v : p1.v;
	min.u = p0.u < p1.u ? p0.u : p1.u;
	max.u = p0.u > p1.u ? p0.u : p1.u;
	if (delta.u == delta.v)
	{
		while (min.u < max.u)
		{
			g42_mlx_pixel_put(data, min.u, min.v, colour);
		}
	}
}
