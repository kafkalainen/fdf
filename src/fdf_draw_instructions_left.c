/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_instructions_left.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:18:09 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/31 07:05:26 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void		fdf_draw_instructions_left(t_data *data, t_uv coord)
{
	data->text_size = 2;
	g42_str_pxl(data, coord, "To rotate and zoom:");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press Q to rotate X-axis clockwise");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press E to rotate X-axis counter-clockwise");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press D to rotate Y-axis clockwise");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press A to rotate Y-axis counter-clockwise");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press W to rotate Z-axis clockwise");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press S to rotate Z-axis counter-clockwise");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press 1 to Zoom + Press 2 to Zoom -");
}
