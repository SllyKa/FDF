/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constructors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:59:45 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/09 19:37:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_window	*init_tcont(void *a, void *b)
{
	t_window		*new_win;

	if (!(new_win = (t_window*)malloc(sizeof(t_window))))
		return (NULL);
	new_win->mx_ptr = a;
	new_win->wn_ptr = b;
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

t_line		*init_tline(t_point *p0, t_point *p1)
{
	t_line		*new_line;

	if(!(new_line = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	new_line->p0 = p0;
	new_line->p1 = p1;
	return (new_line);
}