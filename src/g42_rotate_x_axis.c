/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_rotate_x_axis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:12:32 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 14:24:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <math.h>

void	g42_rotate_x_axis(t_vec3 *vec, double angle)
{
	t_m4x4	m;
	double	c;
	double	s;

	c = cos(angle * (PI / 180));
	s = sin(angle * (PI / 180));
	m = (t_m4x4)
	{{
		{ 1, 0, 0, 0},
		{ 0, c, s, 0},
		{ 0, -s, c, 0},
		{ 0, 0, 0, 1},
	}};
	*vec = g42_multi_vec_matrix(vec, &m);
}
