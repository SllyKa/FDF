/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line_wu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:58:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/09 23:40:27 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static t_point	*dif_ret(t_point *p0, t_point *p1, char isabs)
{
	t_point		*pd;

	pd = init_tpoint(p1->x - p0->x, p1->y - p0->y, 0);
	if (!pd)
		exit(0);
	if (isabs)
	{
		ABS(pd->x);
		ABS(pd->y);
	}
	return (pd);
}

static void		fswap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char		initswap(t_line **ln, t_point **pd, t_line *line)
{
	char		isswap;
	t_point		*p0;
	t_point		*p1;
	
	if(!(p0 = init_tpoint(line->p0->x, line->p0->y, line->p0->clr)))
		exit (0);
	if(!(p1 = init_tpoint(line->p1->x, line->p1->y, line->p1->clr)))
		exit (0);
	if(!(*ln = init_tline(p0, p1)))
		exit (0);	
	*pd = dif_ret(p0, p1, 0);
	isswap = 0;
	if ((*pd)->x < (*pd)->y)
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

static void		put_px_w(t_window *par, t_point *p, char isswap, float a)
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

void			draw_linew(t_window *par, t_line *line)
{
	t_point		*pd;
	t_line		*ln;
	char		isswap;
	float		grad;
	float		y;

	isswap = initswap(&ln, &pd, line);
	put_px_w(par, ln->p0, isswap, 1);
	put_px_w(par, ln->p1, isswap, 1);
	grad = 1;
	if (pd->x)
		grad = (float)pd->y / (float)pd->x;
	y = (float)ln->p0->y + grad;
	(ln->p0->x)++;
	while(ln->p0->x <= ln->p1->x - 1)
	{
		ln->p0->y = (int)y;
		put_px_w(par, ln->p0, isswap, (float)1 - (y - (int)y));
		ln->p0->y = (int)(y + 1);
		put_px_w(par, ln->p0, isswap, (float)(y - ((int)y)));
		y = y + grad;
		(ln->p0->x)++;
	}
}