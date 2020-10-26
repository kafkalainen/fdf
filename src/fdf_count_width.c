/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:53:05 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/26 14:09:30 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "fdf.h"

size_t	*fdf_count_width(char const *s, t_map *map)
{
	size_t		j;

	j = 0;
	map->max_width = 0;
	if (!(map->width = (size_t*)malloc(sizeof(*(map->width)) * map->height + 1)))
		return (NULL);
	while (*s != '\0')
	{
		map->width[j] = 0;
		while (*s != '\n' && *s != '\0')
		{
			while (*s == ' ' && *s != '\0')
				s++;
			if (*s != ' ' && *s != '\n' && *s != '\0')
				map->width[j]++;
			while (*s != ' ' && *s != '\n' && *s != '\0')
				s++;
		}
		if (*s == '\n')
			s++;
		if (map->width[j] > map->max_width)
			map->max_width = map->width[j];
		j++;
	}
	return (map->width);
}
