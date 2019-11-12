/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_coord_rt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:42:13 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:19:42 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rt_map_x(t_pointz *p0, t_transfrm *tr)
{
	double	tmp;

	tmp = p0->y - tr->start->y;
	p0->x = p0->x;
	p0->y = (p0->y - tr->start->y) * cos(tr->angle) +
	(p0->z - tr->start->z) * sin(tr->angle) + tr->start->y;
	p0->z = -tmp * sin(tr->angle) +
	(p0->z - tr->start->z) * cos(tr->angle) + tr->start->z;
}

void		rt_map_y(t_pointz *p0, t_transfrm *tr)
{
	double	tmp;

	tmp = p0->x - tr->start->x;
	p0->x = (p0->x - tr->start->x) * cos(tr->angle) +
	(p0->z - tr->start->z) * sin(tr->angle) + tr->start->x;
	p0->y = p0->y;
	p0->z = -tmp * sin(tr->angle) +
	(p0->z - tr->start->z) * cos(tr->angle) + tr->start->z;
}

void		rt_map_z(t_pointz *p0, t_transfrm *tr)
{
	double	tmp;

	tmp = p0->x - tr->start->x;
	p0->x = (p0->x - tr->start->x) * cos(tr->angle) -
	(p0->y - tr->start->y) * sin(tr->angle) + tr->start->x;
	p0->y = tmp * sin(tr->angle) +
	(p0->y - tr->start->y) * cos(tr->angle) + tr->start->y;
	p0->z = p0->z;
}
