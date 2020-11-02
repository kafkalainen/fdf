/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:39:39 by jnivala           #+#    #+#             */
/*   Updated: 2020/11/02 11:01:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include <stdlib.h>

t_vars	*fdf_init_vars(void)
{
	t_vars	*vars;

	if (!(vars = (t_vars*)malloc(sizeof(t_vars))))
		return (NULL);
	if (!(vars->map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(vars->data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	return (vars);
}
