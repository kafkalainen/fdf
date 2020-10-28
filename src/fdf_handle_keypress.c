/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_keypress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:43:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 15:34:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include "fdf.h"

int		fdf_handle_keypress(int keycode, t_vars *vars)
{
	if (vars && keycode == ESC)
	{
		// mlx_destroy_image(vars->mlx, vars->data.img);
		// mlx_destroy_window(vars->mlx, vars->win);
		// free(vars->mlx);
		exit(EXIT_SUCCESS);
	}
	if (vars && (keycode == KEY_D || keycode == KEY_W
		|| keycode == KEY_A || keycode == KEY_S ||
		keycode == KEY_E || keycode == KEY_Q))
		fdf_rotate_object(keycode, vars);
	if (vars && (keycode == DOWN || keycode == UP
		|| keycode == LEFT || keycode == RIGHT))
		fdf_move_object(keycode, vars);
	if (vars && (keycode == KEY_1 || keycode == KEY_2))
		fdf_scale_object(keycode, vars);
	if (vars && (keycode == KEY_R || keycode == KEY_H))
		fdf_reset_object(keycode, vars);
	if (vars && keycode == KEY_G)
		fdf_iso_object(keycode, vars);
	if (vars && keycode == KEY_F)
		fdf_front_object(keycode, vars);
	return (0);
}
