/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_2d_to_uv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:03:37 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/23 12:56:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_uv	g42_2d_to_uv(t_vec3 coord)
{
	t_uv	screen_coord;

	screen_coord.u = (int)(WIN_WIDTH / 2 + coord.x);
	screen_coord.v = (int)(WIN_HEIGHT / 2 - coord.y);
	return (screen_coord);
}
