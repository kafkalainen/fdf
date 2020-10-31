/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g42_str_pxl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 08:38:48 by jnivala           #+#    #+#             */
/*   Updated: 2020/10/30 18:36:06 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g42.h"
#include "../libft/libft.h"
#include <stdlib.h>

static void		g42_draw_letter(t_data *data, int x, int y, int *letter)
{
	t_uv	cur;
	int		c;
	int		m;
	t_uv	mod;

	cur.v = 0;
	m = data->text_size;
	while (cur.v < 7)
	{
		cur.u = 0;
		while (cur.u < 5)
		{
			c = letter[cur.u + cur.v * 5];
			mod.u = cur.u * m + x;
			mod.v = cur.v * m + y;
			g42_solid_square(data, mod, c, m);
			cur.u++;
		}
		cur.v++;
	}
}

static void		g42_handle_letter(t_data *data, int **tab, t_uv coord, int c)
{
	t_pxl_c	letter;
	int		i;

	i = 0;
	if (c >= 'A' && c <= 'Z')
		letter = g42_pxl_alphabet(c, 0xFF1F1F1F, 0x00FFFFFF);
	if (c >= '0' && c <= '9')
		letter = g42_pxl_numbers(c, 0xFF1F1F1F, 0x00FFFFFF);
	if (c == '!' || c == '?' || c == ':'
		|| c == ';' || c == '+' || c == '-'
		|| c == ' ')
		letter = g42_pxl_numbers(c, 0xFF1F1F1F, 0x00FFFFFF);
	while (i < 36)
	{
		*(*(tab) + i) = letter.c[i];
		i++;
	}
	g42_draw_letter(data, coord.u, coord.v, *tab);
}

void			g42_str_pxl(t_data *data, t_uv coord, char *str)
{
	int		c;
	int		*letter;

	letter = (int*)malloc(sizeof(*letter) * 36);
	while (*str != '\0')
	{
		c = ft_toupper(*str);
		g42_handle_letter(data, &letter, coord, c);
		coord.u += 5 * data->text_size;
		str++;
	}
	ft_memdel((void*)&letter);
}
