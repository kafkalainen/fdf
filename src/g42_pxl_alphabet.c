/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_pxl_alphabet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:16:40 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/28 13:59:56 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"

static t_pxl_c	g42_letter_abcdef(int l, int b, int c)
{
	if (l == 'A')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, c,
			c, b, b, c, b, c, b, b, c, b, c, b, b, b, b, b, b }};
	else if (l == 'B')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, c,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'C')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, b,
			b, b, b, c, b, b, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'D')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, b, b, b, c, b, c, b, b, c, b,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'E')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, c,
			b, b, b, c, b, b, b, b, c, c, c, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, c,
			b, b, b, c, b, b, b, b, c, b, b, b, b, b, b, b, b }};
}

static t_pxl_c	g42_letter_ghijkl(int l, int b, int c)
{
	if (l == 'G')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, c,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'H')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, c,
			c, b, b, c, b, c, b, b, c, b, c, b, b, b, b, b, b }};
	else if (l == 'I')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, c, b, b, b, b, c,
			b, b, b, b, c, b, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'J')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, b, c, b, b, b, b,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'K')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, c,
			b, b, b, c, b, c, b, b, c, b, c, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, b, b, b, c, b, b, b, b, c, b,
			b, b, b, c, b, b, b, b, c, c, c, b, b, b, b, b, b }};
}

static t_pxl_c	g42_letter_mnopqr(int l, int b, int c)
{
	if (l == 'M')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, c, c, b, b, c, c,
			c, b, b, c, b, c, b, b, c, b, c, b, b, b, b, b, b }};
	else if (l == 'N')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, c, c, b, b, c, c,
			c, b, b, c, c, c, b, b, c, b, c, b, b, b, b, b, b }};
	else if (l == 'O')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, b,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'P')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, c,
			c, b, b, c, b, b, b, b, c, b, b, b, b, b, b, b, b }};
	else if (l == 'Q')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, b,
			c, b, b, c, c, c, b, b, b, c, c, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, c, b, b, c, c,
			b, b, b, c, b, c, b, b, c, b, c, b, b, b, b, b, b }};
}

static t_pxl_c	g42_letter_stuvwx(int l, int b, int c)
{
	if (l == 'S')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, c, b, b, b, b, c, c,
			c, b, b, b, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'T')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, c, b, b, b, b, c,
			b, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b, b }};
	else if (l == 'U')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, b,
			c, b, b, c, b, c, b, b, c, c, c, b, b, b, b, b, b }};
	else if (l == 'V')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, b, c,
			c, b, b, b, c, c, b, b, b, b, c, b, b, b, b, b, b }};
	else if (l == 'W')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, c,
			c, b, b, c, c, c, b, b, c, b, c, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, b, c,
			b, b, b, c, b, c, b, b, c, b, c, b, b, b, b, b, b }};
}

t_pxl_c			g42_pxl_alphabet(int l, int b, int c)
{
	if (l >= 'A' && l <= 'F')
		return (g42_letter_abcdef(l, b, c));
	else if (l >= 'G' && l <= 'L')
		return (g42_letter_ghijkl(l, b, c));
	else if (l >= 'M' && l <= 'R')
		return (g42_letter_mnopqr(l, b, c));
	else if (l >= 'S' && l <= 'X')
		return (g42_letter_stuvwx(l, b, c));
	else if (l == 'Y')
		return (t_pxl_c){{
			b, b, b, b, b, b, c, b, c, b, b, c, b, c, b, b, c, c,
			c, b, b, b, c, b, b, b, b, c, b, b, b, b, b, b, b }};
	else
		return (t_pxl_c){{
			b, b, b, b, b, b, c, c, c, b, b, b, b, c, b, b, b, c,
			b, b, b, c, b, b, b, b, c, c, c, b, b, b, b, b, b }};
}
