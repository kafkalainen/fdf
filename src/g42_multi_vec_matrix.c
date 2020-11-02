/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_multi_vec_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:51:20 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 10:36:49 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

t_vec3		g42_multi_vec_matrix(const t_vec3 *src, t_m4x4 *x)
{
	t_vec3		dst;
	double		w;

	dst.x = src->x * x->m[0][0] + src->y * x->m[1][0]
	+ src->z * x->m[2][0] + x->m[3][0];
	dst.y = src->x * x->m[0][1] + src->y * x->m[1][1]
	+ src->z * x->m[2][1] + x->m[3][1];
	dst.z = src->x * x->m[0][2] + src->y * x->m[1][2]
	+ src->z * x->m[2][2] + x->m[3][2];
	w = src->x * x->m[0][3] + src->y * x->m[1][3]
	+ src->z * x->m[2][3] + x->m[3][3];
	dst.c_scale = src->c_scale;
	if (w != 0.0 && w != 1.0)
	{
		dst.x = dst.x / w;
		dst.y = dst.y / w;
		dst.z = dst.z / w;
	}
	return (dst);
}
