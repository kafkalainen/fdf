/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mod_vec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:36:22 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/27 13:01:39 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void		g42_mod_vec(t_map *map, void (*f)(t_vec3*, t_vec3), t_vec3 mod)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (size_t)map->coord_amount;
	if (map != 0)
	{
		while (len)
		{
			f(&map->proj[i], mod);
			i++;
			len--;
		}
	}
	return ;
}
