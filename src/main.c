/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:47:56 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 10:38:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"
#include "g42.h"
#include "fdf.h"
#include <stdio.h>

int		get_key_code(int key, void *param)
{
	if (param == NULL)
	{
		ft_putchar('X');
	}
	ft_putchar(' ');
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int	track_mouse(int x,int y, void *p)
{
	if (p)
	{
		printf("Mouse moving in window, at %dx%d.\n",x,y);
	}
	return (0);
}

void	fdf_rainbow_function(t_colour *colour)
{
	if (colour->r == 255)
	{
		if (colour->g < 256)
			colour->g = colour->g + 1;
	}
	if (colour->g == 255)
	{
		if (colour->r)
		{
			if (colour->r > 0)
				colour->r = colour->r - 1;
		}
		else
		{
			if (colour->b < 256)
				colour->b = colour->b + 1;
		}
	}
	if (colour->b == 255)
	{
		if (colour->b)
		{
			if (colour->g > 0)
				colour->g = colour->g - 1;
		}
		else
		{
			if (colour->r < 256)
				colour->r = colour->r + 1;
		}
	}
}

int		main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
	{
		ft_putstr_fd("Please provide a valid filename. Correct usage ./fdf <filename>\n", 2);
		return (EXIT_FAILURE);
	}
	fdf_file_reader(&vars.map, argv[1]);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (EXIT_FAILURE);
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	if (vars.win == NULL)
		return (EXIT_FAILURE);
	vars.data.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits_per_pixel, &vars.data.line_length, &vars.data.endian);
	fdf_init_camera(&vars.cur);
	fdf_init_view(&vars.map, &vars.cur);
	fdf_draw_wire(&vars.data, &vars.map, vars.map.screen, vars.cur.colour);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	//mlx_key_hook(vars.win, get_key_code, (void*)0);
	//mlx_hook(vars.win, MOTIONNOTIFY, POINTERMOTIONMASK, track_mouse, &vars);
	mlx_hook(vars.win, KEYPRESS, KEYPRESSMASK, fdf_handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (EXIT_SUCCESS);
}
