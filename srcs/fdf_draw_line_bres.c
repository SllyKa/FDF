/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line_bres.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:31:15 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/09 23:41:38 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

static void	min_max(t_point **cp0, t_point **cp1, char c)
{
	t_point		*temp;

	if (((*cp0)->x > (*cp1)->x && c) || ((*cp0)->y > (*cp1)->y && !c))
	{
		temp = *cp0;
		*cp0 = *cp1;
		*cp1 = temp;
	}
}

static void	init_dr_line(t_line *fline, t_point **cp0, t_point **cp1, int *er)
{
	if(!(*cp0 = init_tpoint(fline->p0->x, fline->p0->y, fline->p0->clr)))
		exit (0);
	if(!(*cp1 = init_tpoint(fline->p1->x, fline->p1->y, fline->p1->clr)))
		exit (0);
	*er = 0;
}

static void		fdline_x(t_window *par, t_line *fline, t_point *pd)
{
	char		ds;
	int			er;
	t_point		*cp0;
	t_point		*cp1;

	init_dr_line(fline, &cp0, &cp1, &er);
	ds = 1;
	min_max(&cp0, &cp1, 1);
	if (cp1->y - cp0->y < 0)
		ds = -1;
	while (cp0->x <= cp1->x)
	{
		put_px(par, cp0, 1);
		er += pd->y;
		if (2 * er >= pd->x)
		{
			cp0->y = cp0->y + ds;
			er = er - pd->x;
		}
		(cp0->x)++;
	}
	free(cp0);
	free(cp1);
}

static void		fdline_y(t_window *par, t_line *fline, t_point *pd)
{
	char		ds;
	int			er;
	t_point		*cp0;
	t_point		*cp1;

	init_dr_line(fline, &cp0, &cp1, &er);
	ds = 1;
	min_max(&cp0, &cp1, 0);
	if (cp1->x - cp0->x < 0)
		ds = -1;
	while (cp0->y <= cp1->y)
	{
		put_px(par, cp0, 0);
		er += pd->x;
		if (2 * er >= pd->y)
		{
			cp0->x = cp0->x + ds;
			er = er - pd->y;
		}
		(cp0->y)++;
	}
	free(cp0);
	free(cp1);
}

void		draw_line_bres(t_window *par, t_line *fline)
{
	t_point	*pd;

	if(!(pd = init_tpoint(fline->p0->x - fline->p1->x,
	fline->p0->y - fline->p1->y, 0)))
		exit (0);
	ABS((pd->x));
	ABS((pd->y));
	if (pd->x < pd->y)
		fdline_y(par, fline, pd);
	else
		fdline_x(par, fline, pd);
	free(pd);
}
