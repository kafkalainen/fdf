/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 10:55:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/24 13:08:31 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

size_t	fdf_count_height(char const *s)
{
	size_t			i;
	size_t			height;

	i = 0;
	height = 1;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			height++;
		i++;
	}
	return (height);
}
