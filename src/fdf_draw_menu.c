/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:53:34 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/28 14:54:57 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_draw_menu(t_data *data, int colour)
{
	t_uv	pixel;
	t_uv	instructions;
	t_uv	title;

	instructions.u = 20;
	instructions.v = 10;
	title.u = WIN_WIDTH / 2 - 75;
	title.v = MENU_HEIGHT / 2 - 35;
	pixel.v = 0;
	while (pixel.v < MENU_HEIGHT)
	{
		pixel.u = 0;
		while (pixel.u < WIN_WIDTH)
		{
			g42_mlx_pixel_put(data, pixel.u, pixel.v, colour);
			pixel.u++;
		}
		pixel.v++;
	}
	fdf_draw_instructions(data, instructions);
	fdf_draw_title(data, title);
	return (0);
}
