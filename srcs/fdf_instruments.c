/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_instruments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:16:36 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:22:03 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				make_a_clr(int clr, double a)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if (a > 1 && a < 0)
		return (clr);
	r = (clr >> (2 * 8)) & -1;
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

void			put_bold_px(t_window *par, int x, int y, int clr)
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
		put_bold_px(par, (int)p->x, (int)p->y, p->clr);
	else
		mlx_pixel_put(par->mx_ptr, par->wn_ptr, (int)p->x, (int)p->y, p->clr);
}

t_line			*fill_line(t_pointz *p0, t_pointz *p1)
{
	t_line		*newl;

	newl = init_tline(init_tpointz(p0->x, p0->y, p0->z, p0->clr),
	init_tpointz(p1->x, p1->y, p1->z, p1->clr));
	return (newl);
}
