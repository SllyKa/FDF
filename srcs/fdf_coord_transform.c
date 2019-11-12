/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_coord_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:06:20 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:21:10 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mv_map(t_pointz *p0, t_transfrm *tr)
{
	p0->x = p0->x + tr->mvstep->x;
	p0->y = p0->y + tr->mvstep->y;
	p0->z = p0->z + tr->mvstep->z;
}

void	sc_map(t_pointz *p0, t_transfrm *tr)
{
	p0->x = tr->start->x + (p0->x - tr->start->x) * tr->scale->x;
	p0->y = tr->start->y + (p0->y - tr->start->y) * tr->scale->y;
	p0->z = tr->start->z + (p0->z - tr->start->z) * tr->scale->z;
}

void	fdf_map_trnsf(t_bilist *map, t_transfrm *tr,
void (*f_tr)(t_pointz *, t_transfrm *))
{
	t_pix_lst	*pxl;

	while (map)
	{
		pxl = map->data;
		while (pxl)
		{
			f_tr(pxl->data, tr);
			pxl = pxl->next;
		}
		map = map->next;
	}
}

void	iso_map(t_pointz *p0, t_transfrm *tr)
{
	double	oldx;
	double	oldy;

	oldx = p0->x - tr->start->x;
	oldy = p0->y - tr->start->y;
	p0->x = (oldx - oldy) * cos(tr->angle) + tr->start->x;
	p0->y = -(p0->z - tr->start->z) +
	(oldx + oldy) * sin(tr->angle) + tr->start->y;
}
