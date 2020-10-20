/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_cross_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:23:48 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/18 11:48:12 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

void	g42_cross_product(t_vec3 *a, t_vec3 *b, t_vec3 *cross)
{
	cross->x = a->y * b->z - a->z * b->y;
	cross->y = a->z * b->x - a->x * b->z;
	cross->z = a->x * b->y - a->y * b->x;
}
