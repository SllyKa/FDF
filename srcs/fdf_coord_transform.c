/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_coord_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:06:20 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/11 07:53:47 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		mv_map(t_pointz *p0, t_transfrm *tr)
{
	p0->x = p0->x + tr->start->x;
	p0->y = p0->y + tr->start->y;
	p0->z = p0->z + tr->start->z;
}

static void		scale_map(t_pointz *p0, t_transfrm *tr)
{
	p0->x = p0->x * tr->scale->x;
	p0->y = p0->y * tr->scale->y;
	p0->z = p0->z * tr->scale->z;
}

void			fdf_sc_map(t_bilist *map, t_transfrm *tr)
{
	t_pix_lst	*pxl;
	t_pix_lst	*par_pxl;
	
	par_pxl = NULL;
	while (map)
	{
		pxl = map->data;
		while (pxl)
		{
			scale_map(pxl->data, tr);
			pxl = pxl->next;
		}
		map = map->next;
	}
}

void			fdf_mv_map(t_bilist *map, t_transfrm *tr)
{
	t_pix_lst	*pxl;
	t_pix_lst	*par_pxl;
	
	par_pxl = NULL;
	while (map)
	{
		pxl = map->data;
		while (pxl)
		{
			mv_map(pxl->data, tr);
			pxl = pxl->next;
		}
		map = map->next;
	}
}