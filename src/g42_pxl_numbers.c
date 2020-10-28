/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_pxl_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:18:11 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/28 14:02:37 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

static t_pxl_c	g42_letter_012345(int l, int b, int c)
{
	if (l == '0')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, b,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == '1')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, b, b, b, b, c, b, b, b, b, c,
			b, b, b, b, c, b, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == '2')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, b, c, b, b, c, c,
			c, b, b, c, b, b, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == '3')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, b, c, b, b, b, c,
			c, b, b, b, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == '4')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, c,
			c, b, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, c,
			c, b, b, b, b, c, b, b, c, c, c, b, b, b, b, b, b }};
}

static t_pxl_c	g42_letter_6789(int l, int b, int c)
{
	if (l == '6')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, c,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == '7')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, b, c, b, b, b, c,
			c, b, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b }};
	else if (l == '8')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, c,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == '9')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, c,
			c, b, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b }};
	else if (l == '+')
		return (t_pxl_c){{
			b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, c,
			b, b, b, c, c, c, b, b, b, c, b, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, c, c,
			c, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }};
}

static t_pxl_c	g42_letter_special(int l, int b, int c)
{
	if (l == '?')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, b, b, b, b, b, c, b, b, b, c,
			b, b, b, b, b, b, b, b, b, c, b, b, b, b, b, b, b }};
	else if (l == '!')
		return (t_pxl_c){{
			b, b, b, b, b, b, b, c, b, b, b, b, c, b, b, b, b, c,
			b, b, b, b, b, b, b, b, b, c, b, b, b, b, b, b, b }};
	else if (l == ':')
		return (t_pxl_c){{
			b, b, b, b, b, b, b, b, b, b, b, b, c, b, b, b, b, b,
			b, b, b, b, c, b, b, b, b, b, b, b, b, b, b, b, b }};
	else if (l == ';')
		return (t_pxl_c){{
			b, b, b, b, b, b, b, b, b, b, b, b, c, b, b, b, b, b,
			b, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b,
			b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b }};
}

t_pxl_c			g42_pxl_numbers(int l, int b, int c)
{
	if (l >= '0' && l <= '5')
		return (g42_letter_012345(l, b, c));
	else if ((l >= '6' && l <= '9') || l == '+' || l == '-')
		return (g42_letter_6789(l, b, c));
	else if (l == ':' || l == ';' || l == '!' || l == '?'
		|| l == ' ')
		return (g42_letter_special(l, b, c));
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, c,
			c, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b, b }};
}
