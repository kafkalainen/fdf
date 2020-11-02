/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_del_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:21:44 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 11:02:58 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "g42.h"
#include "../libft/libft.h"

int		fdf_del_vars(t_vars **vars)
{
	if (*vars)
	{
		ft_memdel((void**)&((*vars)->data));
		ft_memdel((void**)&((*vars)->map));
		ft_memdel((void**)&((*vars)));
	}
	return (fdf_error("ERROR: Invalid file descriptor."));
}
