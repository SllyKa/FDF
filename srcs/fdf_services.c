/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_services.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:33:53 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:23:17 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fswap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		val_to_ptz(t_pointz *p0, double valx, double valy, double valz)
{
	p0->x = valx;
	p0->y = valy;
	p0->z = valz;
}

void		clear_tr_dr(t_container *box, void (*f)(t_pointz *, t_transfrm *))
{
	mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
	fdf_map_trnsf(box->map, box->tr, f);
	fdf_draw_map(box->par, box->map);
}
