/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_solid_square.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:12:16 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/15 09:12:48 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void		g42_mlx_solid_square(t_data *data, int offset_x, int offset_y, int color, int size)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			g42_mlx_pixel_put(data, x + offset_x, y + offset_y, color);
			x++;
		}
	y++;
	}
}
