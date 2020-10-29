/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_hex_to_trgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:09:15 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 08:50:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

t_colour	g42_hex_to_trgb(int trgb)
{
	t_colour	colour;

	colour.t = g42_get_transparency(trgb) / 256 / 256 / 256;
	colour.r = g42_get_red(trgb) / 256 / 256;
	colour.g = g42_get_green(trgb) / 256;
	colour.b = g42_get_blue(trgb);
	return (colour);
}
