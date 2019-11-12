/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constructors_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:18:58 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 06:20:46 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_bilist		*init_bilist(t_pix_lst *px_lst, size_t s)
{
	t_bilist	*new_bi;

	if (!(new_bi = (t_bilist*)malloc(sizeof(t_bilist))))
		return (NULL);
	new_bi->data = px_lst;
	new_bi->s = s;
	new_bi->next = NULL;
	new_bi->prev = NULL;
	new_bi->head = NULL;
	return (new_bi);
}

t_transfrm		*init_transfrm(t_pointz *st, t_pointz *scale,
t_pointz *mvstep, double angle)
{
	t_transfrm		*t;

	t = (t_transfrm*)malloc(sizeof(t_transfrm));
	t->scale = scale;
	t->start = st;
	t->mvstep = mvstep;
	t->angle = angle;
	t->map_cpy = NULL;
	return (t);
}

t_container		*init_container(t_window *par, t_bilist *map,
t_transfrm *tr, double y)
{
	t_container		*cntr;

	cntr = (t_container*)malloc(sizeof(t_container));
	cntr->map = map;
	cntr->par = par;
	cntr->tr = tr;
	cntr->y = y;
	return (cntr);
}