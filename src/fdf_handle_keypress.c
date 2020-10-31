/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handle_keypress.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:43:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/31 12:19:28 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int		fdf_handle_keypress(int keycode, t_vars *vars)
{
	if (vars && keycode == ESC)
	{
		vars = fdf_clean(&vars);
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
	if (vars && keycode == KEY_C)
		fdf_change_colour(keycode, vars);
	if (vars && (keycode == KEY_3 || keycode == KEY_4))
		fdf_manipulate_y(keycode, vars);
	return (0);
}
