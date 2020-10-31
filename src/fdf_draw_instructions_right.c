/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_instructions_right.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 07:01:40 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/31 12:14:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void		fdf_draw_instructions_right(t_data *data, t_uv coord)
{
	g42_str_pxl(data, coord, "To switch views:");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press 3 to increase y axis and 4 to flatten");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press R to reset view");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press F to switch to top-down view");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press G to switch to isometric view");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press H to switch to horizontal view");
	coord.v += 7 * 2;
	g42_str_pxl(data, coord, "Press C to switch colour");
}
