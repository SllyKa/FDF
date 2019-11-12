/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:11:37 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 12:53:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void		fill_n_draw(t_window *par,t_pointz *p0, t_pointz *p1)
{
	t_line	*lne;

	lne = fill_line(p0, p1);
	draw_linew(par, lne);
	free_line(lne);
}

void			fdf_draw_map(t_window *par, t_bilist *map)
{
	t_pix_lst	*pxl;
	t_pix_lst	*par_pxl;
	
	par_pxl = NULL;
	while (map)
	{
		pxl = map->data;
		if (map->prev)
			par_pxl = map->prev->data;
		while (pxl->next)
		{
			fill_n_draw(par, pxl->data, pxl->next->data);
			if (par_pxl)
			{
				fill_n_draw(par, par_pxl->data, pxl->data);
				par_pxl = par_pxl->next;
			}
			pxl = pxl->next;
		}
		if (!pxl->next && par_pxl)
			fill_n_draw(par, par_pxl->data, pxl->data);
		map = map->next;
	}
}