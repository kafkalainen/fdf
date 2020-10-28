/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:22:06 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 09:54:40 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fdf.h"

size_t		fdf_idx(size_t x, size_t z, t_map *map)
{
	size_t	idx;

	idx = 0;
	while (z)
	{
		z--;
		idx += map->width[z];
	}
	idx += x;
	return (idx);
}
