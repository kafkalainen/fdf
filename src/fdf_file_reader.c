/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:30:47 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/26 13:41:55 by jnivala          ###   ########.fr       */
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

static void mypause ( void )
{
	printf ("Press [Enter] to get next line. . .");
	fflush (stdout);
	getchar();
}

static int	fdf_check_legal_characters(char *trimmed)
{
	char	legal[21];
	size_t	len;

	ft_strcpy(legal, "X0123456789ABCDEF ,\n");
	len = ft_strlen(trimmed);
	while (--len)
	{
		if (!(ft_strchr(legal, ft_toupper(trimmed[len]))))
			return (INVALID_CHARACTERS);
	}
	return (0);
}

static int	fdf_validation(char *str, t_map *map, char **arr)
{
	char	*trimmed;
	size_t	len;
	int		valid;

	if (!(trimmed = ft_strtrim(str)))
		return (MALLOC_FAILED);
	ft_strdel(&str);
	len = ft_count_wrds(trimmed, ' ');
	fdf_count_height(trimmed, map);
	fdf_count_width(trimmed, map);
	printf("%ld\n", len);
	// printf("Width %ld\n", width);
	// printf("Height %ld\n", height);
	// if (map->width[0] * map->height != len)
	// {
	// 	printf("Width x height %ld\n", map->width * map->height);
	// 	printf("all coords %ld\n", len);
	// 	return (3);
	// }
	valid = fdf_check_legal_characters(trimmed);
	if (!(arr = ft_strsplit(trimmed, ' ')))
		return (MALLOC_FAILED);
	return (valid);
}


static int fdf_read_function(int fd, char **map)
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
	size_t		i;
	size_t		z;
	t_vec3		coord;

	i = 0;
	z = 0;
	coord.x = 0;
	coord.z = 0;
	map->depth = 0;
	if (!(map->coord = (t_vec3*)malloc(sizeof(*map->coord) * map->max_width * map->height + 1)))
		return (MALLOC_FAILED);
	if (!(map->screen = (t_uv*)malloc(sizeof(*(map->screen)) * map->max_width * map->height + 1)))
		return (MALLOC_FAILED);
	while (coord.z < map->height)
	{
		coord.x = 0;
		while (coord.x < map->width[z])
		{
 			map->coord[i].x = coord.x;
 			map->coord[i].z = coord.z;
 			map->coord[i].y = fdf_depth_parser(*arr[i]);
 			coord.x++;
 			i++;
 		}
 		coord.z++;
		z++;
 	}
	return (0);
}

int			fdf_file_reader(t_map *map, char *filename)
{
	int		err;
	int		fd;
	char	*str;
	char	**arr;

	map->width = 0;
	map->height = 0;
	map->depth = 0;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		if (fdf_read_function(fd, &str))
			ft_putendl_fd("ERROR: Memory allocation failed while reading map.", 2);
		ft_putendl_fd(str, 2);
		mypause();
		err = fdf_validation(str, map, arr);
		if (err == 0)
			(ft_putendl_fd("Valid line.", 2));
		if (err == 3)
			(ft_putendl_fd("ERROR: Invalid line length.", 2));
		if (err == 2)
			(ft_putendl_fd("ERROR: Invalid line.", 2));
		if (err == MALLOC_FAILED)
			(ft_putendl_fd("ERROR: Memory allocation failed while reading map.", 2));
		mypause();
		err = fdf_read_coord(map, &arr);
		mypause();
	}
	close(fd);
	return (0);
}
