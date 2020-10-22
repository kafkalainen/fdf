/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:03:39 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 10:27:47 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "fdf.h"

int		fdf_close_window(int keycode, t_vars *vars)
{
	if (keycode == ESC && vars)
	{
		mlx_destroy_image(vars->mlx, vars->data.img);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}
