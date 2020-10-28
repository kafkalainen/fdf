/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 10:24:41 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 13:45:01 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	fdf_print_cam(t_cam *cur)
{
	printf("cur ang_x %f\n", cur->ang_x);
	printf("cur ang_y %f\n", cur->ang_y);
	printf("cur ang_z %f\n", cur->ang_z);
	printf("cur offset_x %f\n", cur->vector.x);
	printf("cur offset_y %f\n", cur->vector.y);
	printf("cur scale %f\n", cur->dist);
}
