/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mod_pts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:21:04 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 10:46:39 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void		g42_mod_pts(t_map *map, void (*f)(t_vec3*, double), double mod)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (size_t)map->coord_amount;
	if (map != 0)
	{
		while (len)
		{
			f(&map->coord[i], mod);
			i++;
			len--;
		}
	}
	return ;
}
