/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:53:05 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/31 08:59:54 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fdf.h"
#include "../libft/libft.h"

static size_t	fdf_row_width(const char *s)
{
	size_t	width;

	width = 0;
	while (*s != '\n' && *s != '\0')
	{
		while (*s == ' ' && *s != '\0')
			s++;
		if (*s != ' ' && *s != '\n' && *s != '\0')
			width++;
		while (*s != ' ' && *s != '\n' && *s != '\0')
			s++;
	}
	return (width);
}

size_t			*fdf_count_width(char const *s, t_map *map)
{
	size_t		i;
	char		*nl;

	i = 0;
	nl = (char*)s;
	map->max_width = 0;
	map->width = (size_t*)malloc(sizeof(*(map->width)) * map->height + 1);
	if (!(map->width))
		return (NULL);
	while (i < map->height)
	{
		map->width[i] = fdf_row_width(nl);
		nl = ft_strchr(nl, '\n');
		if (nl != NULL && *nl == '\n')
			nl++;
		if (map->width[i] > map->max_width)
			map->max_width = map->width[i];
		i++;
	}
	return (map->width);
}
