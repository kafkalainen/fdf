/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_exit_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:43:38 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/16 16:20:08 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		fdf_handle_keypress(int keycode, t_vars *vars)
{
	if (vars && keycode == ESC)
		exit(EXIT_SUCCESS);
	if (vars && keycode == KEY_W)
		fdf_image_change(vars);
	return (0);
}
