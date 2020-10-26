/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_depth_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:40:07 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/24 12:58:25 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"

int		fdf_depth_parser(char *elem)
{
	size_t	len;
	int		nb;

	len = ft_strlen(elem);
	if (len > 3 && elem[0] == '0' && ft_toupper(elem[1]) == 'X')
		nb = ft_atoi_base(elem + 2, 16);
	else
		nb = ft_atoi_base(elem, 10);
	return (nb);
}
