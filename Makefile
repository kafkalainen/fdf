# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/03 18:33:41 by joonasniv         #+#    #+#              #
#    Updated: 2020/10/31 07:43:16 by jnivala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

source_dir = src
LIBFT = libft/
include_dirs = libft /usr/include mlx_linux $(source_dir)
INC = /usr/include
INCLIB = $(INC)/../lib

SRC = $(addprefix $(source_dir)/,\
	main.c\
	g42_get_transparency.c\
	g42_get_blue.c\
	g42_get_green.c\
	g42_get_red.c\
	g42_create_trgb.c\
	g42_invert_trgb.c\
	g42_mlx_pixel_put.c\
	g42_mlx_draw_line_dda.c\
	g42_draw_line_bre.c\
	g42_mlx_draw_x_y_line.c\
	g42_mlx_draw_diagonal.c\
	g42_solid_square.c\
	g42_cross_product.c\
	g42_dot_product.c\
	g42_normalize_vector.c\
	g42_2d_to_ndc.c\
	g42_2d_to_uv.c\
	g42_ndc_to_raster_space.c\
	g42_rotate_x_axis.c\
	g42_rotate_y_axis.c\
	g42_rotate_z_axis.c\
	g42_scale_point.c\
	g42_mod_pts.c\
	g42_mod_vec.c\
	g42_multi_vec_matrix.c\
	g42_translate.c\
	g42_str_pxl.c\
	g42_pxl_alphabet.c\
	g42_pxl_numbers.c\
	g42_hex_to_trgb.c\
	g42_trgb_to_hex.c\
	g42_c_grad.c\
	fdf_handle_keypress.c\
	fdf_draw_wire.c\
	fdf_draw_line.c\
	fdf_translate_coordinates.c\
	fdf_idx.c\
	fdf_move_object.c\
	fdf_scale_object.c\
	fdf_rotate_object.c\
	fdf_file_reader.c\
	fdf_count_height.c\
	fdf_count_width.c\
	fdf_depth_parser.c\
	fdf_check_valid_depth.c\
	fdf_double_parser.c\
	fdf_print_cam.c\
	fdf_reset_object.c\
	fdf_iso_object.c\
	fdf_front_object.c\
	fdf_init_camera.c\
	fdf_init_view.c\
	fdf_draw_menu.c\
	fdf_draw_background.c\
	fdf_draw_instructions_left.c\
	fdf_draw_instructions_right.c\
	fdf_draw_title.c\
	fdf_count_colour_scale.c\
	fdf_error.c\
	fdf_clean.c\
)
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(addprefix -I,$(include_dirs))

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ) src/g42.h src/fdf.h
	make -C $(LIBFT) fclean && make -C $(LIBFT)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L$(INCLIB) -Llibft/ -lft -Imlx_linux -lXext -lX11 -lm -lz -o $@

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJ)

fclean: clean
	rm $(LIBFT)libft.a
	rm -f $(NAME)

re: fclean all

debug: $(OBJ) src/g42.h src/fdf.h
	make -C $(LIBFT) fclean && make debug -C $(LIBFT)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L$(INCLIB) -Llibft/ -lft -Imlx_linux -lXext -lX11 -lm -lz -o $@
