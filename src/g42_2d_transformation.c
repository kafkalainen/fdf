/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_2d_transformation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:20:26 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 12:01:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <math.h>

/*t_uv	g42_uv_transformation(t_vec3 *a)
{
	t_uv	coord;

	coord.u= 400 + 30 * (a->x-a->z)/sqrt(2);
	coord.v= 300 + 30 * (a->x+2*a->y+a->z)/sqrt(6);
	return coord;
}*/

t_vec2	g42_2d_transformation(t_vec3 *a)
{

	// t_m4x4	world_to_camera;
	t_vec2			coord;

	/*world_to_camera.m[0][0] = 0.707107;
	world_to_camera.m[0][1] = -0.331295;
	world_to_camera.m[0][2] = 0.624695;
	world_to_camera.m[0][3] = 0;
	world_to_camera.m[1][0] = 0;
	world_to_camera.m[1][1] = 0.883452;
	world_to_camera.m[1][2] = 0.468521;
	world_to_camera.m[1][3] = 0;
	world_to_camera.m[2][0] = -0.707107;
	world_to_camera.m[2][1] = -0.331295;
	world_to_camera.m[2][2] = 0.624695;
	world_to_camera.m[2][3] = 0;
	world_to_camera.m[3][0] = -1.63871;
	world_to_camera.m[3][0] = -5.747777;
	world_to_camera.m[3][0] = -40.400412;
	world_to_camera.m[3][0] = 1;*/
	/*Weak perspective projection*/
	coord.x = (float)a->x/(float)a->z;
	coord.y = (float)a->y/(float)a->z;
	return coord;
}
