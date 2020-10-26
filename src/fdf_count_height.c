/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:55:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/26 13:50:57 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

size_t	fdf_count_height(char const *s, t_map *map)
{
	map->height = 1;
	while (*s != '\0')
	{
		if (*s == '\n')
			map->height++;
		s++;
	}
	return (map->height);
}
