/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:18:55 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/23 14:30:10 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

void	fdf_draw_line(t_data *data ,t_uv p0, t_uv p1, int colour)
{
	t_uv	delta;

	delta.u = ft_abs(p1.u - p0.u);
	delta.v = ft_abs(p1.v - p0.v);
	if (delta.u == 0 || delta.v == 0)
		g42_mlx_draw_x_y_line(data, p0, p1, colour);
	//else if (delta.u == delta.v && delta.u != 0 && delta.v != 0)
	//	g42_mlx_draw_diagonal(data, p0, p1, colour);
	else
		g42_mlx_draw_line_bre(data, p0, p1, colour);
}
