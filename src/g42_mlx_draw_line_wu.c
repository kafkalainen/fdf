/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_mlx_draw_line_wu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:25:51 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/22 17:44:14 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/libft.h"

void g42_mlx_draw_line_wu(t_data *data, t_uv p0, t_uv p1, int colour)
{
	int yLonger;
	yLonger = 0;
	int incrementVal;
	int endVal;
	int shortLen = p1.v - p0.v;
	int longLen = p1.u - p0.u;
	if (ft_abs(shortLen)>ft_abs(longLen)) {
		int swap=shortLen;
		shortLen=longLen;
		longLen=swap;
		yLonger=1;
	}
	endVal=longLen;
	if (longLen<0) {
		incrementVal=-1;
		longLen=-longLen;
	} else incrementVal=1;
	int decInc;
	if (longLen==0) decInc=0;
	else decInc = (shortLen << 16) / longLen;
	int j=0;
	if (yLonger) {
		for (int i=0;i!=endVal;i+=incrementVal) {
			g42_mlx_pixel_put(data, (int)p0.u+(j >> 16), (int)p0.v+i, colour);
			j+=decInc;
		}
	} else {
		for (int i=0;i!=endVal;i+=incrementVal) {
			g42_mlx_pixel_put(data, (int)p0.u+i, (int)p0.v+(j >> 16), colour);
			j+=decInc;
		}
	}
}
