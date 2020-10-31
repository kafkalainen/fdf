/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_normalize_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:56:46 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 18:39:34 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "../libft/libft.h"

void	g42_normalize_vector(t_vec3 *v)
{
	unsigned int	len2;
	unsigned int	inv_len;

	len2 = v->x * v->x + v->y * v->y + v->z * v->z;
	if (len2 > 0)
	{
		inv_len = 1 / ft_sqrt(len2);
		v->x *= inv_len;
		v->y *= inv_len;
		v->z *= inv_len;
	}
}
