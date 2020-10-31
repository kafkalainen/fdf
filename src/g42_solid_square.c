/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_solid_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:12:16 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 18:36:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void		g42_solid_square(t_data *data, t_uv offset, int c, int s)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < s)
	{
		x = 0;
		while (x < s)
		{
			g42_mlx_pixel_put(data, x + offset.u, y + offset.v, c);
			x++;
		}
		y++;
	}
}
