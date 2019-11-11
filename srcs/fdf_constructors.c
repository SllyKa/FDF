/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constructors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:59:45 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/11 03:52:17 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_window	*init_tcont(int x, int y, char *name)
{
	t_window		*new_win;

	if (!(new_win = (t_window*)malloc(sizeof(t_window))))
		return (NULL);
	new_win->mx_ptr = mlx_init();
	new_win->wn_ptr = mlx_new_window(new_win->mx_ptr, x, y, name);
	return (new_win);
}

t_point		*init_tpoint(int x, int y, int clr)
{
	t_point		*new_point;

	if (!(new_point = (t_point*)malloc(sizeof(t_point))))
		return (NULL);
	new_point->x = x;
	new_point->y = y;
	new_point->clr = clr;
	return (new_point);
}

t_pointz		*init_tpointz(double x, double y, double z, int clr)
{
	t_pointz	*new_pointz;

	if(!(new_pointz = (t_pointz*)malloc(sizeof(t_pointz))))
		return (NULL);
	new_pointz->x = x;
	new_pointz->y = y;
	new_pointz->z = z;
	new_pointz->clr = clr;
	return (new_pointz);
}

t_line		*init_tline(t_pointz *p0, t_pointz *p1)
{
	t_line		*new_line;

	if(!(new_line = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	new_line->p0 = p0;
	new_line->p1 = p1;
	new_line->pp0 = NULL;
	new_line->pp1 = NULL;
	return (new_line);
}

t_pix_lst	*init_tpxlist(t_pointz *pntz)
{
	t_pix_lst	*new_px_lst;

	if (!(new_px_lst = (t_pix_lst*)malloc(sizeof(t_pix_lst))))
		return (NULL);
	new_px_lst->data = pntz;
	new_px_lst->next = NULL;
	return (new_px_lst);
}
