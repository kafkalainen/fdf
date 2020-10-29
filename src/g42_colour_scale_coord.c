/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_colour_scale_coord.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:59:02 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 09:41:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

int		g42_colour_scale_coord(double scale, int colour)
{
	t_colour	trgb;

	trgb = g42_hex_to_trgb(colour);
	trgb.r = (int)(scale * trgb.r);
	trgb.g = (int)(scale * trgb.g);
	trgb.b = (int)(scale * trgb.b);
	return (g42_trgb_to_hex(trgb));
}
