/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_2d_to_ndc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:20:47 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/20 12:05:18 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*t_vec2	g42_2d_to_ndc(t_vec2 proj_coord)
{
	t_vec2	ndc;
	t_vec2	invert_view;

	invert_view.x = 1.0f / WIN_WIDTH;
	invert_view.y = 1.0f / WIN_HEIGHT;
	ndc.x = 2.0f * proj_coord.x * invert_view.x - 1.0f;
	ndc.y = 2.0f * -proj_coord.y * invert_view.y + 1.0f;
	return (ndc);
}*/

t_vec2	g42_2d_to_ndc(t_vec2 proj_coord)
{
	t_vec2	ndc;

	ndc.x = (proj_coord.x + WIN_WIDTH / 2) / WIN_WIDTH;
	ndc.y = (proj_coord.y + WIN_HEIGHT / 2) / WIN_HEIGHT;
	return (ndc);
}
