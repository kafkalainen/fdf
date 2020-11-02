/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:47:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 11:25:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "g42.h"
#include "fdf.h"

int				main(int argc, char **argv)
{
	t_vars		*vars;

	if (argc != 2)
		return (fdf_error("Please provide a valid name. ./fdf <filename>"));
	if (!(vars = fdf_init_vars()))
		return (EXIT_FAILURE);
	if (fdf_file_reader(vars->map, argv[1]))
		return (fdf_error(fdf_del_vars(&vars)));
	if (!(vars->mlx = mlx_init()))
		return (EXIT_FAILURE);
	if (!(vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		return (EXIT_FAILURE);
	vars->data->img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->data->addr = mlx_get_data_addr(vars->data->img,
		&vars->data->bpp, &vars->data->llen, &vars->data->endian);
	fdf_init_camera(&vars->cur);
	fdf_init_view(vars->map, &vars->cur);
	fdf_draw_wire(vars->data, vars->map, vars->map->screen, vars->cur.colour);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	mlx_hook(vars->win, KEYPRESS, KEYPRESSMASK, fdf_handle_keypress, vars);
	mlx_loop(vars->mlx);
	return (EXIT_SUCCESS);
}
