/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_front_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:45:52 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 10:36:14 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx_linux/mlx.h"

static t_vec3	fdf_center_object(t_vars *vars)
{
	t_vec3	center;

	center.x = vars->map->max_width / 2 * vars->cur.dist;
	center.y = vars->map->height * vars->cur.dist;
	center.z = 0.0;
	return (center);
}

int				fdf_front_object(int keycode, t_vars *vars)
{
	if (vars->cur.ang_x == -90.0 && vars->cur.ang_y == 0.0
		&& vars->cur.ang_z == 0.0)
		return (0);
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img, &vars->data->bpp,
		&vars->data->llen, &vars->data->endian);
	fdf_init_view(vars->map, &vars->cur);
	if (keycode == KEY_F)
	{
		g42_mod_pts(vars->map, &g42_rotate_x_axis, 90.0);
		vars->cur.ang_x = 90.0;
		vars->cur.ang_y = 0.0;
		vars->cur.ang_z = 0.0;
	}
	g42_mod_vec(vars->map, &g42_translate, fdf_center_object(vars));
	g42_mod_pts(vars->map, &g42_scale_point, 0.5);
	fdf_translate_coordinates(vars->map, &vars->cur);
	fdf_draw_wire(vars->data, vars->map, vars->map->screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}
