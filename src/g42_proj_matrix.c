/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_proj_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:19:43 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/19 19:50:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "fdf.h"
#include "math.h"

void	g42_proj_matrix(t_vec3 a)
{
	t_projection	proj;
	t_m4x4			matrix;

	proj.f_near = 0.1f;
	proj.f_far = 1000.0f;
	proj.f_fov = 90.0f;
	proj.f_aspect_ratio = (float)WIN_HEIGHT / (float)WIN_WIDTH;
	proj.f_fov_rad = 1.0f / tanf(proj.f_fov * 0.5f / 180.0f * 3.14159f);

	matrix.m[0][0] = proj.f_aspect_ratio * proj.f_fov_rad;
	matrix.m[1][1] = proj.f_fov_rad;
	matrix.m[2][2] = proj.f_far / (proj.f_far - proj.f_near);
	matrix.m[3][2] = (-proj.f_far * proj.f_near) / (proj.f_far - proj.f_near);
	matrix.m[2][3] = 1.0f;
	matrix.m[2][3] = 0.0f;
}
