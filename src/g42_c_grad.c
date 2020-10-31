/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_c_grad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:59:02 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 13:07:53 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "g42.h"
#include "math.h"

static double	g42_traveled_dist(t_uv *p0, t_uv *p1, t_uv *s)
{
	double		total_dist;
	double		trav_dist;

	if (p0->u == p1->u && s->u == p1->u && p0->v != p1->v)
	{
		trav_dist = p1->v - p0->v;
		total_dist = p1->v - s->v;
	}
	else if (p0->v == p1->v && s->v == p1->v && p0->u != p1->u)
	{
		trav_dist = p1->u - p0->u;
		total_dist = p1->u - s->u;
	}
	else
	{
		trav_dist = ft_sqrt(ft_pow_of_2(p1->u - p0->u, 2.0)
			+ ft_pow_of_2(p1->v - p0->v, 2.0));
		total_dist = ft_sqrt(ft_pow_of_2(p1->u - s->u, 2.0)
			+ ft_pow_of_2(p1->v - s->v, 2.0));
	}
	return (trav_dist / total_dist);
}

int				g42_horizontal_line(double scale, t_colour *brightest)
{
	t_colour	new;

	new.t = (int)((scale) * brightest->t);
	new.r = (int)((scale) * brightest->r);
	new.g = (int)((scale) * brightest->g);
	new.b = (int)((scale) * brightest->b);
	return (g42_trgb_to_hex(new));
}

int				g42_c_grad(t_uv p0, t_uv p1, t_uv s, int colour)
{
	t_colour	brightest;
	t_colour	new;
	double		frac;

	frac = g42_traveled_dist(&p0, &p1, &s);
	brightest = g42_hex_to_trgb(colour);
	if (p0.s_scale > p1.s_scale)
	{
		new.t = (int)((frac * p0.s_scale) * brightest.t);
		new.r = (int)((frac * p0.s_scale) * brightest.r);
		new.g = (int)((frac * p0.s_scale) * brightest.g);
		new.b = (int)((frac * p0.s_scale) * brightest.b);
		return (g42_trgb_to_hex(new));
	}
	else if (p0.s_scale == p1.s_scale)
		return (g42_horizontal_line(p0.s_scale, &brightest));
	else
	{
		new.t = (int)((1 - frac * p1.s_scale) * brightest.t);
		new.r = (int)((1 - frac * p1.s_scale) * brightest.r);
		new.g = (int)((1 - frac * p1.s_scale) * brightest.g);
		new.b = (int)((1 - frac * p1.s_scale) * brightest.b);
		return (g42_trgb_to_hex(new));
	}
}
