/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:30:47 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/29 13:10:23 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "fdf.h"
#include "stdlib.h"

// static void	mypause(void)
// {
// 	printf("Press [Enter] to get next line. . .");
// 	fflush(stdout);
// 	getchar();
// }

static int	fdf_check_legal_characters(char *str)
{
	char		legal[21];
	size_t		len;

	ft_strcpy(legal, "X0123456789ABCDEF ,\n");
	len = ft_strlen(str);
	while (--len)
	{
		if (!(ft_strchr(legal, ft_toupper(str[len]))))
			return (INVALID_CHARACTERS);
	}
	return (0);
}

static int	fdf_map_mem_allocation(char *str, t_map *map, char ***arr)
{
	map->width = 0;
	map->height = 0;
	map->min_depth = 0;
	map->pts = ft_count_wrds(str, ' ');
	fdf_count_height(str, map);
	fdf_count_width(str, map);
	if (!(map->coord = (t_vec3*)malloc(sizeof(*map->coord) * map->pts + 1)))
		return (MALLOC_FAILED);
	if (!(map->proj = (t_vec3*)malloc(sizeof(*(map->proj)) * map->pts + 1)))
		return (MALLOC_FAILED);
	if (!(map->screen = (t_uv*)malloc(sizeof(*(map->screen)) * map->pts + 1)))
		return (MALLOC_FAILED);
	ft_replace_char(str, '\n', ' ');
	//ft_putendl_fd(str, 1);
	if (!(*arr = ft_strsplit(str, ' ')))
		return (MALLOC_FAILED);
	return (0);
}

static int	fdf_read_function(int fd, char **map)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*temp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (temp)
		{
			if (!(temp = ft_strjoin(buf, temp)))
				return (MALLOC_FAILED);
		}
		else
		{
			if (!(temp = ft_strdup(buf)))
				return (MALLOC_FAILED);
		}
	}
	if (temp)
	{
		*map = ft_strdup(temp);
		ft_strdel(&temp);
	}
	return (0);
}

int			fdf_read_coord(t_map *map, char ***arr)
{
	t_counter	c;
	t_vec3		coord;

	c.i = 0;
	c.j = 0;
	c.k = 0;
	coord.z = 0;
	if (arr == NULL)
		return (1);
	while (coord.z < map->height)
	{
		coord.x = 0;
		while (coord.x < map->width[c.k])
		{
			map->coord[c.i].x = coord.x;
			map->coord[c.i].z = coord.z;
			map->coord[c.i].y = fdf_depth_parser(map, *(*(arr) + c.j++));
			c.i++;
			coord.x++;
		}
		coord.z++;
		c.k++;
	}
	return (0);
}

int			fdf_file_reader(t_map *map, char *filename)
{
	int			err;
	int			fd;
	char		*str;
	char		**arr;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		if (fdf_read_function(fd, &str))
			ft_putendl_fd("ERROR: Memory allocation failed while reading map.", 2);
		err = fdf_check_legal_characters(str);
		if (err == INVALID_CHARACTERS)
			ft_putendl_fd("ERROR: Invalid line.", 2);
		else
			ft_putendl_fd("Map has only valid characters, proceeding.", 1);
		err = fdf_map_mem_allocation(str, map, &arr);
		if (err == MALLOC_FAILED)
			ft_putendl_fd("ERROR: Memory allocation failed while reading map.", 2);
		ft_putendl_fd("Memory allocation succeeded, reading coordinates.", 1);
		err = fdf_read_coord(map, &arr);
		err = fdf_count_colour_scale(map);
		//mypause();
	}
	close(fd);
	return (0);
}
