/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line_wu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:58:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:26:24 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static t_pointz		*dif_ret(t_pointz *p0, t_pointz *p1, char isabs)
{
	t_pointz		*pd;

	pd = init_tpointz(p1->x - p0->x, p1->y - p0->y, 0, 0);
	if (!pd)
		exit(0);
	if (isabs)
	{
		pd->x = fabs(pd->x);
		pd->y = fabs(pd->y);
	}
	return (pd);
}

static char			initswap(t_line **ln, t_pointz **pd, t_line *line)
{
	char		isswap;
	t_pointz	*p0;
	t_pointz	*p1;

	if (!(p0 = init_tpointz(line->p0->x, line->p0->y, 0, line->p0->clr)))
		exit(0);
	if (!(p1 = init_tpointz(line->p1->x, line->p1->y, 0, line->p1->clr)))
		exit(0);
	if (!(*ln = init_tline(p0, p1)))
		exit(0);
	*pd = dif_ret(p0, p1, 0);
	isswap = 0;
	if (fabs((*pd)->x) < fabs((*pd)->y))
	{
		fswap(&(p0->x), &(p0->y));
		fswap(&(p1->x), &(p1->y));
		fswap(&((*pd)->x), &((*pd)->y));
		isswap = 1;
	}
	if (p0->x > p1->x)
	{
		fswap(&((*ln)->p0->x), &((*ln)->p1->x));
		fswap(&((*ln)->p0->y), &((*ln)->p1->y));
	}
	return (isswap);
}

static void			put_px_w(t_window *par, t_point *p, char isswap, double a)
{
	int tmp;

	if (isswap)
	{
		tmp = p->y;
		p->y = p->x;
		p->x = tmp;
	}
	tmp = p->clr;
	p->clr = make_a_clr(p->clr, a);
	put_px(par, p, 0);
	p->clr = tmp;
	if (isswap)
	{
		tmp = p->y;
		p->y = p->x;
		p->x = tmp;
	}
}

static	t_line		*top_draw(t_line *line, char *isswap,
double *grad, double *y)
{
	t_pointz	*pd;
	t_line		*ln;
	t_point		*pp0;
	t_point		*pp1;

	*isswap = initswap(&ln, &pd, line);
	*grad = 1;
	if (pd->x)
		*grad = pd->y / pd->x;
	*y = ln->p0->y + *grad * (round(ln->p0->x) - ln->p0->x) + *grad;
	pp0 = init_tpoint(round(ln->p0->x), round(ln->p0->y), ln->p0->clr);
	pp1 = init_tpoint(round(ln->p1->x), round(ln->p1->y), ln->p1->clr);
	free(pd);
	ln->pp0 = pp0;
	ln->pp1 = pp1;
	return (ln);
}

void				draw_linew(t_window *par, t_line *line)
{
	t_line		*ln;
	char		isswap;
	double		grad;
	double		y;

	ln = top_draw(line, &isswap, &grad, &y);
	put_px_w(par, ln->pp0, isswap, 1);
	put_px_w(par, ln->pp1, isswap, 1);
	(ln->pp0->x)++;
	while (ln->pp0->x <= ln->pp1->x - 1)
	{
		ln->pp0->y = (int)y;
		put_px_w(par, ln->pp0, isswap, 1 - (y - (int)y));
		ln->pp0->y = (int)y + 1;
		put_px_w(par, ln->pp0, isswap, (y - ((int)y)));
		y = y + grad;
		(ln->pp0->x)++;
	}
	free_line(ln);
}
