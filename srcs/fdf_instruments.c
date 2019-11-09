/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_instruments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:16:36 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/09 23:09:31 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				make_a_clr(int clr, float a)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (a > 1 && a < 0)
		return (clr);

	r = (clr >> (2*8)) & -1;
	g = (clr >> 8) & -1;
	b = clr & -1;
	r = (unsigned char)((r * a));
	g = (unsigned char)((g * a));
	b = (unsigned char)((b * a));
	return (make_clr(r, g, b));
}

int				make_clr(unsigned char r, unsigned char g, unsigned char b)
{
	int clr;

	clr = 0;
	clr |= (clr | r) << (2 * 8);
	clr |= ((clr & 0) | g) << 8;
	clr |= clr | b;
	return (clr);
}

static void		put_bold_px(t_window *par, int x, int y, int clr)
{
	mlx_pixel_put(par->mx_ptr, par->wn_ptr, x + 1, y, clr);
	mlx_pixel_put(par->mx_ptr, par->wn_ptr, x - 1, y, clr);
	mlx_pixel_put(par->mx_ptr, par->wn_ptr, x, y, clr);
	mlx_pixel_put(par->mx_ptr, par->wn_ptr, x, y - 1, clr);
	mlx_pixel_put(par->mx_ptr, par->wn_ptr, x, y + 1, clr);
}

void			put_px(t_window *par, t_point *p, char b)
{
	if (b)
		put_bold_px(par, p->x, p->y, p->clr);
	else
		mlx_pixel_put(par->mx_ptr, par->wn_ptr, p->x, p->y, p->clr);	
}
