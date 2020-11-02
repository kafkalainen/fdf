/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:32:21 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 11:31:32 by jnivala          ###   ########.fr       */
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
# define KEY_3 51
# define KEY_4 52
# define KEY_C 99
# define KEY_R 114
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define INVALID_CHARACTERS 2
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MENU_HEIGHT 200
# define BUFF_SIZE 1024
# define SNOW 0xfffafa
# define MISTYROSE 0xffe4e1
# define LIGHTBLUE 0xadd8e6
# define POWDERBLUE 0xb0e0e6
# define PALETURQUOISE 0xafeeee
# define TURQUOISE 0x5ca08e
# define PALEGREEN 0x98fb98
# define LIMEGREEN 0x32cd32
# define LIGHTYELLOW 0xffffe0
# define SANDYBROWN 0xf4a460
# define ORANGE 0xffa500
# define HOTPINK 0xff69b4
# define LIGHTPINK 0xffb6c1
# define VIOLETRED 0xd02090
# include "g42.h"
# include <string.h>

int		fdf_change_colour(int keycode, t_vars *vars);

int		fdf_check_valid_depth(char *str, char *validate);

size_t	fdf_count_height(char const *s, t_map *map);

size_t	*fdf_count_width(char const *s, t_map *map);

double	fdf_depth_parser(t_map *map, char *elem);

double	fdf_double_parser(int begin, int end);

void	fdf_draw_wire(t_data *data, t_map *map, t_uv *coord, int colour);

void	fdf_draw_line(t_data *data, t_uv p0, t_uv p1, int colour);

int		fdf_draw_menu(t_data *data, int colour);

int		fdf_draw_background(t_data *data);

int		fdf_draw_instructions_right(t_data *data, t_uv coord);

int		fdf_draw_instructions_left(t_data *data, t_uv coord);

void	fdf_draw_title(t_data *data, t_uv coord);

int		fdf_error(char *message);

int		fdf_file_reader(t_map *map, char *filename);

int		fdf_front_object(int keycode, t_vars *vars);

int		fdf_handle_keypress(int keycode, t_vars *vars);

size_t	fdf_idx(size_t x, size_t y, t_map *map);

int		fdf_init_view(t_map *map, t_cam *cur);

int		fdf_init_camera(t_cam *cam);

t_vars	*fdf_init_vars(void);

int		fdf_iso_object(int keycode, t_vars *vars);

int		fdf_move_object(int keycode, t_vars *vars);

int		fdf_reset_object(int keycode, t_vars *vars);

int		fdf_rotate_object(int keycode, t_vars *vars);

int		fdf_scale_object(int keycode, t_vars *vars);

t_uv	*fdf_translate_coordinates(t_map *map, t_cam *cam);

int		fdf_count_colour_scale(t_map *map);

t_vars	*fdf_clean(t_vars **vars);

char	*fdf_del_vars(t_vars **vars);

int		fdf_manipulate_y(int keycode, t_vars *vars);

#endif
