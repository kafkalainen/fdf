/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:43:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 16:57:18 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"
#include "g42.h"
#include <stdio.h>

void		g42_mlx_draw_grid(t_data *img, t_map *map)
{
	// int		i;
	// int		u;
	// int		v;
	// t_vec2	coord[36];
	// t_uv	uv[36];
	// i = 0;
	t_vec3	point1;
	t_vec3	point2;
	t_vec3	point3;
	t_vec3	point4;
	t_vec3	point5;
	t_vec2	p1;
	t_vec2	p2;
	t_vec2	p3;
	t_vec2	p4;
	t_vec2	p5;
	// t_vec3	change_x;
	// t_vec3	change_y;
	// t_vec3	change_z;
	// t_vec3	scale;
	//t_vec2	ndc0;
	//t_vec2	ndc1;
	// t_uv	uv0;
	// t_uv	uv1;
	t_uv	u21;
	t_uv	u22;
	t_uv	u23;
	t_uv	u24;
	t_uv	u25;

	point1.x = 0;
	point1.y = 0;
	point1.z = 0;
	point2.x = 10.0f;
	point2.y = 0;
	point2.z = 0;
	point3.x = 10.0f;
	point3.y = 0;
	point3.z = 10.0f;
	point4.x = 0;
	point4.y = 0;
	point4.z = 10.0f;
	point5.x = 5.0f;
	point5.y = 10.0f;
	point5.z = 5.0f;
	/*To get isometric view of the object, set the Rotation order to zyx,
	the z Rotation to 45 and the y Rotation to 35.264.*/
	g42_rotate_z_axis(&point1, 45.0f);
	g42_rotate_y_axis(&point1, 35.264f);
	g42_rotate_z_axis(&point2, 45.0f);
	g42_rotate_y_axis(&point2, 35.264f);
	g42_rotate_z_axis(&point3, 45.0f);
	g42_rotate_y_axis(&point3, 35.264f);
	g42_rotate_z_axis(&point4, 45.0f);
	g42_rotate_y_axis(&point4, 35.264f);
	g42_rotate_z_axis(&point5, 45.0f);
	g42_rotate_y_axis(&point5, 35.264f);
	g42_scale_point(&point1, 10);
	g42_scale_point(&point2, 10);
	g42_scale_point(&point3, 10);
	g42_scale_point(&point4, 10);
	g42_scale_point(&point5, 10);
	g42_clip_point(&point1);
	g42_clip_point(&point2);
	g42_clip_point(&point3);
	g42_clip_point(&point4);
	g42_clip_point(&point5);
	printf("x is %f, y is %f and z is %f\n", point1.x, point1.y, point1.z);
	printf("x is %f, y is %f and z is %f\n", point2.x, point2.y, point2.z);
	printf("x is %f, y is %f and z is %f\n", point3.x, point3.y, point3.z);
	printf("x is %f, y is %f and z is %f\n", point4.x, point4.y, point4.z);
	printf("x is %f, y is %f and z is %f\n", point5.x, point5.y, point5.z);
	// ndc0.x = 1.0f;
	// ndc0.y = 1.0f;
	// ndc1.x = 0.0f;
	// ndc1.y = 0.0f;
	p1 = g42_2d_transformation(&point1);
	p2 = g42_2d_transformation(&point2);
	p3 = g42_2d_transformation(&point3);
	p4 = g42_2d_transformation(&point4);
	p5 = g42_2d_transformation(&point5);
	u21.u = p1.x;
	u21.v = p1.y;
	u22.u = p2.x;
	u22.v = p2.y;
	u23.u = p3.x;
	u23.v = p3.y;
	u24.u = p4.x;
	u24.v = p4.y;
	u25.u = p5.x;
	u25.v = p5.y;
	//p1 = g42_2d_to_ndc(p1);
	//p2 = g42_2d_to_ndc(p2);
	//p3 = g42_2d_to_ndc(p3);
	//p4 = g42_2d_to_ndc(p4);
	//p5 = g42_2d_to_ndc(p5);
	// printf("x is %f, y is %f\n", p1.x, p1.y);
	// printf("x is %f, y is %f\n", p2.x, p2.y);
	// printf("x is %f, y is %f\n", p3.x, p3.y);
	// printf("x is %f, y is %f\n", p4.x, p4.y);
	// printf("x is %f, y is %f\n", p5.x, p5.y);
	//u21 = g42_ndc_to_raster_space(p1);
	//u22 = g42_ndc_to_raster_space(p2);
	//u23 = g42_ndc_to_raster_space(p3);
	//u24 = g42_ndc_to_raster_space(p4);
	//u25 = g42_ndc_to_raster_space(p5);
	//g42_ndc_to_raster_space(ndc0),
	//g42_mlx_draw_line_dda(img, &uv0, &uv1, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u21, &u22, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u22, &u23, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u23, &u24, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u24, &u21, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u25, &u21, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u25, &u22, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u25, &u23, 0x0000FF00);
	g42_mlx_draw_line_dda(img, &u25, &u24, 0x0000FF00);
	printf("%p\n", map);
	/*while (i < 36)
	{
		if (map->coord[i].z > 0)
		{
			coord[i] = g42_2d_transformation(&map->coord[i]);
			coord[i] = g42_2d_to_ndc(coord[i]);
			uv[i] = g42_ndc_to_raster_space(coord[i]);
		}
		i++;
	}*/
	/*printf("%p\n", img);
	while (i < 36)
	{
		printf("Screen x is %f, and y is %f\n", uv[i].u, uv[i].v);
		i++;
	}*/
	/*v = 0;
	while (v + 1 < 6)
	{
		u = 0;
		while (u + 1 < 6)
		{
			g42_mlx_draw_line_dda(img, &uv[u + v * 6], &uv[u + v * 6 + 1], 0x0000FF00);
			g42_mlx_draw_line_dda(img, &uv[u + v * 6], &uv[u + (v + 1) * 6], 0x0000FF00);
			u++;
		}
		v++;
	}*/
}
