/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:30:47 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/23 16:00:48 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include "fdf.h"

static void mypause ( void )
{
	printf ("Press [Enter] to get next line. . .");
	fflush (stdout);
	getchar();
}

static int	fdf_check_legal_characters(char *trimmed)
{
	char	legal[20];
	size_t	len;

	ft_strcpy(legal, "xX0123456789ABCDEF ");
	len = ft_strlen(trimmed);
	while (--len)
	{
		if (!(ft_strchr(legal, trimmed[len])))
			return (2);
	}
	return (0);
}

static size_t	fdf_count_columns(char const *s)
{
	size_t			i;
	size_t			column_count;

	i = 0;
	column_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != ' ' && s[i] != '\0')
			column_count++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (column_count);
}

static int	fdf_validation(char *str, t_map *map)
{
	char	*trimmed;
	char	**arr;
	size_t	width;
	int		valid;

	if (!(trimmed = ft_strtrim(str)))
		return (1);
	ft_strdel(&str);
	width = fdf_count_columns(trimmed);
	printf("%ld", width);
	map->width = width;
	valid = fdf_check_legal_characters(trimmed);
	if (!(arr = ft_strsplit(trimmed, ' ')))
		return (1);
	return (valid);
}

int			fdf_file_reader(t_map *map, char *filename)
{
	int		err;
	int		fd;
	char	*str;

	map->depth = 1;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &str) == 1)
		{
			printf("%ld", map->depth);
			err = fdf_validation(str, map);
			if (err == 0)
				(ft_putendl_fd("Valid line.", 2));
			if (err == 2)
				(ft_putendl_fd("Invalid line.", 2));
			if (err == 1)
				(ft_putendl_fd("Memory allocation failed reading map.", 2));
			mypause();
		}
	}
	close(fd);
	return (0);
}

// {
// 	size_t		i;
// 	t_vec3		coord;

// 	i = 0;
// 	coord.x = 0;
// 	coord.z = 0;
// 	map->coord_amount = 36;
// 	map->height = 6;
// 	map->depth = 2;
// 	map->width = 6;
// 	if (!(map->coord = (t_vec3*)malloc(sizeof(*map->coord) * map->coord_amount + 1)))
// 		return (0);
// 	if (!(map->screen = (t_uv*)malloc(sizeof(*(map->screen)) * map->coord_amount + 1)))
// 		return (0);
// 	while (coord.z < map->height)
// 	{
// 		coord.x = 0;
// 		while (coord.x < map->width)
// 		{
// 			map->coord[i].x = coord.x;
// 			map->coord[i].z = coord.z;
// 			map->coord[i].y = 0;
// 			coord.x++;
// 			i++;
// 		}
// 		coord.z++;
// 	}
// 	map->coord[7].y = 1;
// 	map->coord[8].y = 1;
// 	map->coord[9].y = 1;
// 	map->coord[10].y = 1;
// 	map->coord[13].y = 1;
// 	map->coord[14].y = 2;
// 	map->coord[15].y = 2;
// 	map->coord[16].y = 1;
// 	map->coord[19].y = 1;
// 	map->coord[20].y = 2;
// 	map->coord[21].y = 2;
// 	map->coord[22].y = 1;
// 	map->coord[25].y = 1;
// 	map->coord[26].y = 1;
// 	map->coord[27].y = 1;
// 	map->coord[28].y = 1;
// 	return (1);
// }
