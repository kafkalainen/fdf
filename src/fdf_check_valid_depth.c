/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_valid_depth.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:47:36 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 11:33:11 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

int		fdf_check_valid_depth(char *str, char *validate)
{
	size_t	len;

	len = ft_strlen(str);
	while (--len)
	{
		if (!(ft_strchr(validate, ft_toupper(str[len]))))
			return (INVALID_CHARACTERS);
	}
	return (0);
}
