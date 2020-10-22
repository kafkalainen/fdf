/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scale_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:20:11 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 17:31:41 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "fdf.h"
#include "../libft/libft.h"

int		fdf_scale_object(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	vars->data.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data.addr = mlx_get_data_addr(vars->data.img, &vars->data.bits_per_pixel, &vars->data.line_length, &vars->data.endian);
	if (keycode == KEY_1)
		g42_mod_pts(&vars->map, &g42_scale_point, 1.5f);
	if (keycode == KEY_2)
		g42_mod_pts(&vars->map, &g42_scale_point, 0.5f);
	fdf_translate_coordinates(&vars->map);
	fdf_draw_wire(&vars->data, &vars->map, vars->map.screen);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (0);
}
