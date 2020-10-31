/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:30:47 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/31 09:26:27 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "fdf.h"

static int	fdf_check_legal_characters(char *str)
{
	size_t		len;
	static char legal[22] = {
		'X', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', ' ', ',', '\n', '-'
		};

	len = ft_strlen(str);
	while (--len)
	{
		if (!(ft_strchr(legal, ft_toupper(str[len]))))
		{
			ft_putchar(str[len]);
			ft_putchar('\n');
			return (INVALID_CHARACTERS);
		}
	}
	return (0);
}

static char	**fdf_map_mem_allocation(char *str, t_map *map)
{
	char **arr;

	map->width = 0;
	map->height = 0;
	map->max_depth = 0;
	map->min_depth = 0;
	map->pts = ft_count_wrds(str, ' ');
	fdf_count_height(str, map);
	fdf_count_width(str, map);
	if (!(map->coord = (t_vec3*)malloc(sizeof(*map->coord) * map->pts + 1)))
		return (NULL);
	if (!(map->proj = (t_vec3*)malloc(sizeof(*(map->proj)) * map->pts + 1)))
		return (NULL);
	if (!(map->screen = (t_uv*)malloc(sizeof(*(map->screen)) * map->pts + 1)))
		return (NULL);
	ft_replace_char(str, '\n', ' ');
	if (!(arr = ft_strsplit(str, ' ')))
		return (NULL);
	return (arr);
}

static char	*fdf_read_function(int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*map;
	char		*temp;

	map = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (map)
		{
			temp = ft_strjoin(map, buf);
			ft_strdel(&map);
			map = ft_strdup(temp);
			if (!temp || !map)
				return (NULL);
			ft_strdel(&temp);
		}
		else
		{
			if (!(map = ft_strdup(buf)))
				return (NULL);
		}
	}
	return (map);
}

static void	fdf_read_coord(t_map *map, char ***arr)
{
	size_t		i;
	t_vec3		coord;

	i = 0;
	coord.z = 0;
	map->min_depth = fdf_depth_parser(map, *(*(arr)));
	map->max_depth = fdf_depth_parser(map, *(*(arr)));
	while (coord.z < map->height)
	{
		coord.x = 0;
		while (coord.x < map->width[(size_t)coord.z])
		{
			map->coord[i].x = coord.x;
			map->coord[i].z = coord.z;
			map->coord[i].y = fdf_depth_parser(map, *(*(arr) + i));
			i++;
			coord.x++;
		}
		coord.z++;
	}
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
		if (!(str = fdf_read_function(fd)))
			return (fdf_error("ERROR: Memory allocation fail reading file."));
		err = fdf_check_legal_characters(str);
		if (err == INVALID_CHARACTERS)
			return (fdf_error("ERROR: Invalid characters."));
		else
			ft_putendl_fd("Map has only valid characters, proceeding.", 1);
		if (!(arr = fdf_map_mem_allocation(str, map)))
			return (fdf_error("ERROR: Memory allocation fail creating map."));
		ft_strdel(&str);
		ft_putendl_fd("Memory allocation succeeded, reading coordinates.", 1);
		fdf_read_coord(map, &arr);
		arr = ft_strarrdel(&arr, map->pts);
		close(fd);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
