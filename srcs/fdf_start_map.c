/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_start_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:30:23 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/13 14:43:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

t_transfrm		*start_map(t_bilist *map, double y)
{
	t_transfrm		*tr;
	t_pointz		*scl;

	scl = init_tpointz(30, 30, 30, 0);
	while (((int)(800 + map->s / 2) +
	(800 - (int)(800 + map->s / 2)) * scl->x) < 0)
		val_to_ptz(scl, scl->x - 1, scl->y - 1, scl->z - 1);
	while (((int)(600 + y / 2) +
	(600 - (int)(600 + y / 2)) * scl->y) < 0)
		val_to_ptz(scl, scl->x - 1, scl->y - 1, scl->z - 1);
	while (((int)(50 + 50 / 2) +
	(50 - (int)(50 + 50 / 2)) * scl->z) < 0)
		val_to_ptz(scl, scl->x - 1, scl->y - 1, scl->z - 1);
	tr = init_transfrm(init_tpointz(800 + map->s / 2, 600 + y / 2, 50, 0), scl,
	init_tpointz(800, 600, 50, 0), 0.1);
	tr->map_cpy = cpy_map(map);
	fdf_map_trnsf(map, tr, mv_map);
	fdf_map_trnsf(map, tr, sc_map);
	return (tr);
}

void			reset_map(t_container *box)
{
	free_sbilist(&(box->map));
	box->map = box->tr->map_cpy;
	free_stransfrm(&(box->tr));
	box->tr = start_map(box->map, box->y);
	mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
}
