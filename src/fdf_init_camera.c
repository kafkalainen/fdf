/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:20:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 14:59:19 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_init_camera(t_cam *cam)
{
	cam->ang_x = 0.0;
	cam->ang_y = 0.0;
	cam->ang_z = 0.0;
	cam->dist = 0.0;
	cam->vector.x = 0.0;
	cam->vector.y = 0.0;
	cam->vector.z = 0.0;
	return (0);
}
