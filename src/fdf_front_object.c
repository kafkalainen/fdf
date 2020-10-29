/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_front_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:45:52 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 09:37:01 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx_linux/mlx.h"

int		fdf_front_object(int keycode, t_vars *vars)
{
	if (vars->cur.ang_x == -90.0 && vars->cur.ang_y == 0.0
		&& vars->cur.ang_z == 0.0)
		return (0);
	mlx_destroy_image(vars->mlx, vars->data.img);
	vars->data.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	fdf_init_view(&vars->map, &vars->cur);
	if (keycode == KEY_F)
	{
		g42_mod_pts(&vars->map, &g42_rotate_x_axis, -90.0);
		vars->cur.ang_x = -90.0;
		vars->cur.ang_y = 0.0;
		vars->cur.ang_z = 0.0;
	}
	fdf_print_cam(&vars->cur);
	fdf_translate_coordinates(&vars->map, &vars->cur);
	fdf_draw_wire(&vars->data, &vars->map, vars->map.screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
