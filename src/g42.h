/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 08:32:27 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 12:10:15 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G42_H
# define G42_H
# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
# define RESIZEREQUEST 25
# define CIRCULATENOTIFY 26
# define CIRCULATEREQUEST 27
# define PROPERTYNOTIFY 28
# define SELECTIONCLEAR 29
# define SELECTIONREQUEST 30
# define SELECTIONNOTIFY 31
# define COLORMAPNOTIFY 32
# define CLIENTMESSAGE 33
# define MAPPINGNOTIFY 34
# define GENERICEVENT 35
# define LASTEVENT 36
# define NOEVENTMASK 0L
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)
# define BUTTONPRESSMASK (1L<<2)
# define BUTTONRELEASEMASK (1L<<3)
# define ENTERWINDOWMASK (1L<<4)
# define LEAVEWINDOWMASK (1L<<5)
# define POINTERMOTIONMASK (1L<<6)
# define POINTERMOTIONHINTMASK (1L<<7)
# define BUTTON1MOTIONMASK (1L<<8)
# define BUTTON2MOTIONMASK (1L<<9)
# define BUTTON3MOTIONMASK (1L<<10)
# define BUTTON4MOTIONMASK (1L<<11)
# define BUTTON5MOTIONMASK (1L<<12)
# define BUTTONMOTIONMASK (1L<<13)
# define KEYMAPSTATEMASK (1L<<14)
# define EXPOSUREMASK (1L<<15)
# define VISIBILITYCHANGEMASK (1L<<16)
# define STRUCTURENOTIFYMASK (1L<<17)
# define RESIZEREDIRECTMASK (1L<<18)
# define SUBSTRUCTURENOTIFYMASK (1L<<19)
# define SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define FOCUSCHANGEMASK (1L<<21)
# define PROPERTYCHANGEMASK (1L<<22)
# define COLORMAPCHANGEMASK (1L<<23)
# define OWNERGRABBUTTONMASK (1L<<24)
# include <string.h>

typedef struct	s_m4x4 {
	float	m[4][4];
}				t_m4x4;

typedef struct	s_projection {
	float	f_near;
	float	f_far;
	float	f_fov;
	float	f_aspect_ratio;
	float	f_fov_rad;
}				t_projection;

typedef struct	s_uv {
	float		u;
	float		v;
}				t_uv;

typedef struct	s_vec2 {
	float		x;
	float		y;
	int			colour;
}				t_vec2;

typedef struct	s_vec3 {
	float		x;
	float		y;
	float		z;
	int			colour;
}				t_vec3;

typedef struct	s_tri {
	t_vec3		tri[3];
}				t_tri;

typedef struct	s_map {
	t_vec3		*coord;
	size_t		height;
	size_t		depth;
	size_t		width;
	size_t		coord_amount;
}				t_map;

typedef struct	s_colour {
	int			t;
	int			r;
	int			g;
	int			b;
}				t_colour;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		data;
	t_map		map;
}				t_vars;

int				g42_create_trgb(int t, int r, int g, int b);

int				g42_get_transparency(int trgb);

int				g42_get_red(int trgb);

int				g42_get_green(int trgb);

int				g42_get_blue(int trgb);

int				g42_invert_trgb(int t, int r, int g, int b);

void			g42_mlx_pixel_put(t_data *data, int x, int y, int color);

void			g42_mlx_solid_square(t_data *data, int off_x, int off_y, int color, int size);

void			g42_mlx_draw_line_dda(t_data *img, t_uv *p0, t_uv *p1, int colour);

void			g42_mlx_draw_line_bre(t_data *img, t_uv *p0, t_uv *p1, int colour);

void			g42_normalize_vector(t_vec3 *v);

int				g42_dot_product(t_vec3 *a, t_vec3 *b);

void			g42_cross_product(t_vec3 *a, t_vec3 *b, t_vec3 *cross);

void			g42_mlx_draw_grid(t_data *img, t_map *map);

t_vec2			g42_2d_transformation(t_vec3 *a);

t_vec2			g42_2d_to_ndc(t_vec2 proj_coord);

t_uv			g42_ndc_to_raster_space(t_vec2 ndc);

#endif