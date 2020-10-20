/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_normalize_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:56:46 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/17 17:05:23 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <math.h>

void	g42_normalize_vector(t_vec3 *v)
{
	unsigned int	len2;
	unsigned int	invLen;

	len2 = v->x * v->x + v->y * v->y + v->z * v->z;
	if (len2 > 0)
	{
		invLen = 1 / sqrt(len2);
		v->x *= invLen;
		v->y *= invLen;
		v->z *= invLen;
	}
}
