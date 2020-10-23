/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:39:19 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/23 09:35:31 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "fdf.h"
#include "../libft/libft.h"

int		fdf_image_change(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	vars->data.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	if (keycode == KEY_Q)
		g42_mod_pts(&vars->map, &g42_rotate_x_axis, -30.0);
	if (keycode == KEY_E)
		g42_mod_pts(&vars->map, &g42_rotate_x_axis, 30.0);
	if (keycode == KEY_D)
		g42_mod_pts(&vars->map, &g42_rotate_y_axis, 30.0);
	if (keycode == KEY_A)
		g42_mod_pts(&vars->map, &g42_rotate_y_axis, -30.0);
	if (keycode == KEY_W)
		g42_mod_pts(&vars->map, &g42_rotate_z_axis, 30.0);
	if (keycode == KEY_S)
		g42_mod_pts(&vars->map, &g42_rotate_z_axis, -30.0);
	fdf_translate_coordinates(&vars->map);
	// while(i < vars->map.coord_amount)
	// {
	// 	printf("Changed coord %ld: Screen x is %d, and y is %d\n", i, vars->map.screen[i].u, vars->map.screen[i].v);
	// 	i++;
	// }
	fdf_draw_wire(&vars->data, &vars->map, vars->map.screen);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
