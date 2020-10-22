/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_clip_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:19:43 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/21 09:27:25 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "fdf.h"
#include "math.h"

void	g42_clip_point(t_vec3 *a)
{
	t_m4x4			matrix;

	float f_near = 0.1f;
	float f_far = 1000.0f;
	float f_fov = 90.0f;
	float f_aspect_ratio = (float)WIN_HEIGHT / (float)WIN_WIDTH;
	float f_fov_rad = 1.0f / tanf(f_fov * 0.5f / 180.0f * 3.14159f);

	// matrix.m[0][0] = f_aspect_ratio * f_fov_rad;
	// matrix.m[1][1] = f_fov_rad;
	// matrix.m[2][2] = f_far / (f_far - f_near);
	// matrix.m[3][2] = (-f_far * f_near) / (f_far - f_near);
	// matrix.m[2][3] = 1.0f;
	// matrix.m[3][3] = 0.0f;

	matrix.m[0][0] = f_aspect_ratio * f_fov_rad;
	matrix.m[0][1] = 0;
	matrix.m[0][2] = 0;
	matrix.m[0][3] = 0;
	matrix.m[1][0] = 0;
	matrix.m[1][1] = f_fov_rad;
	matrix.m[1][2] = 0;
	matrix.m[1][3] = 0;
	matrix.m[2][0] = 0;
	matrix.m[2][1] = 0;
	matrix.m[2][2] = f_far / (f_far - f_near);
	matrix.m[2][3] = (-f_far * f_near) / (f_far - f_near);
	matrix.m[3][0] = 0;
	matrix.m[3][1] = 0;
	matrix.m[3][2] = 1.0f;
	matrix.m[3][3] = 0.0f;
	*a = g42_multi_vec_matrix(a, &matrix);
}
