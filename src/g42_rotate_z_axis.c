/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_rotate_z_axis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:21:32 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/21 09:13:47 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <math.h>
/* cos(theta) -sin(theta) 0
** sin(theta) cos(theta)  0
**     0          0       1
*/
void	g42_rotate_z_axis(t_vec3 *vec, double angle)
{
	t_m4x4	m;

	m.m[0][0] = cos(angle * (PI / 180));
	m.m[0][1] = -sin(angle * (PI / 180));
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = sin(angle * (PI / 180));
	m.m[1][1] = cos(angle * (PI / 180));
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	*vec = g42_multi_vec_matrix(vec, &m);
}