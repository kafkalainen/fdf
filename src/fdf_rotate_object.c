/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:39:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 09:37:40 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "fdf.h"
#include "../libft/libft.h"

int		fdf_rotate_object(int keycode, t_vars *vars)
{
	double	mod;

	mlx_destroy_image(vars->mlx, vars->data.img);
	vars->data.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	if (keycode == KEY_Q || keycode == KEY_E)
	{
		mod = (keycode == KEY_Q ? 15.0 : -15.0);
		g42_mod_pts(&vars->map, &g42_rotate_x_axis, mod);
		vars->cur.ang_x += mod;
	}
	if (keycode == KEY_D || KEY_A)
	{
		mod = (keycode == KEY_D ? 15.0 : -15.0);
		g42_mod_pts(&vars->map, &g42_rotate_y_axis, mod);
		vars->cur.ang_y += mod;
	}
	if (keycode == KEY_W || keycode == KEY_S)
	{
		mod = (keycode == KEY_W ? 15.0 : -15.0);
		g42_mod_pts(&vars->map, &g42_rotate_z_axis, mod);
		vars->cur.ang_z += mod;
	}
	fdf_print_cam(&vars->cur);
	fdf_translate_coordinates(&vars->map, &vars->cur);
	fdf_draw_wire(&vars->data, &vars->map, vars->map.screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
