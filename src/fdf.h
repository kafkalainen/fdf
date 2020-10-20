/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:32:21 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 09:43:50 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 100
# define KEY_D 115
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# include "g42.h"

int		fdf_handle_keypress(int keycode, t_vars *vars);

int		fdf_image_change(t_vars *vars);

int		fdf_init_map(t_map *map);

#endif
