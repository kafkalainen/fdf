/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:32:21 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/23 14:44:40 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_E 101
# define KEY_1 49
# define KEY_2 50
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# include "g42.h"
# include <string.h>

int		fdf_file_reader(t_map *map, char *filename);

int		fdf_handle_keypress(int keycode, t_vars *vars);

int		fdf_image_change(int keycode, t_vars *vars);

int		fdf_move_object(int keycode, t_vars *vars);

int		fdf_scale_object(int keycode, t_vars *vars);

int		fdf_init_map(t_map *map);

void	fdf_draw_wire(t_data *data, t_map *map, t_uv *coord);

void	fdf_draw_line(t_data *data ,t_uv p0, t_uv p1, int colour);

t_uv	*fdf_translate_coordinates(t_map *map);

size_t		fdf_idx(size_t x, size_t y, t_map *map);

#endif
