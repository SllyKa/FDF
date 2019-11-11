/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_instruments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:16:36 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/11 07:26:23 by gbrandon         ###   ########.fr       */
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
		put_bold_px(par, (int)p->x, (int)p->y, p->clr);
	else
		mlx_pixel_put(par->mx_ptr, par->wn_ptr, (int)p->x, (int)p->y, p->clr);	
}


t_line			*fill_line(t_pointz *p0, t_pointz *p1, t_transfrm *tr)
{
	t_line		*newl;
	(void)tr;
	
	newl = init_tline(init_tpointz(p0->x, p0->y, p0->z, p0->clr), init_tpointz(p1->x, p1->y, p1->z, p1->clr));
	return (newl);
}

/*t_line			*fill_line(t_pointz *p0, t_pointz *p1, t_transfrm *tr)
{
	t_line		*newl;
	t_pointz	*a;
	t_pointz	*pp0;
	t_pointz	*pp1;

	a = init_tpointz(p0->x * tr->scale->x + tr->start->x,
	p0->y * tr->scale->y + tr->start->y, p0->z * tr->scale->z + tr->start->z, p0->clr);

	a->x = p0->x * 20;
	a->y = p0->y * 20 * cos(1.5) + p0->z * 20 * sin(1.5);
	a->z = -p0->y * 20 * sin(1.5) + p0->z * 20 * cos(1.5);

	//pp0 = init_tpointz((a->x - a->y) * cos(0.46373398), -a->z + (a->x + a->y) * sin(0.46373398), a->z, a->clr);
	pp0 = init_tpointz(a->x, a->y, a->z, a->clr);
	a->x = p1->x * tr->scale->x + tr->start->x;
	a->y = p1->y * tr->scale->y + tr->start->y;
	a->z = p1->z * tr->scale->z + tr->start->z;
	a->clr = p1->clr;

	a->x = p1->x * 20;
	a->y = p1->y * 20 * cos(1.5) + p1->z * 20 * sin(1.5);
	a->z = -p1->y * 20 * sin(1.5) + p1->z * 20 * cos(1.5);

	//pp1 = init_tpointz((a->x - a->y) * cos(0.46373398), -a->z + (a->x + a->y) * sin(0.46373398), a->z, a->clr);
	pp1 = init_tpointz(a->x, a->y, a->z, a->clr);
	newl = init_tline(pp0, pp1);
	return (newl);
}*/
