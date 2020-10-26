/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:32:21 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/26 12:59:34 by jnivala          ###   ########.fr       */
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
# define MALLOC_FAILED 1
# define INVALID_CHARACTERS 2
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define BUFF_SIZE 1024
# include "g42.h"
# include <string.h>

size_t	fdf_count_height(char const *s, t_map *map);

size_t	*fdf_count_width(char const *s, t_map *map);

int		fdf_depth_parser(char const *elem);

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
