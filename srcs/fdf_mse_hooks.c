/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mse_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:16:39 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 04:37:11 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int			mse_sc(int button, int x, int y, t_container *box)
{
	double xx;
	double yy;
	
	if (button == 5)
	{
		val_to_ptz(box->tr->scale, 1.1, 1.1, 1.1);
		xx = box->tr->start->x;
		yy = box->tr->start->y;
		val_to_ptz(box->tr->start, x, y, box->tr->start->z);
		clear_tr_dr(box, sc_map);
		box->tr->start->x = ((xx - x) * box->tr->scale->x) + x;
		box->tr->start->y = ((yy - y) * box->tr->scale->y) + y;
	}
	if (button == 4)
	{
		val_to_ptz(box->tr->scale, 0.9, 0.9, 0.9);
		xx = box->tr->start->x;
		yy = box->tr->start->y;
		val_to_ptz(box->tr->start, x, y, box->tr->start->z);
		clear_tr_dr(box, sc_map);
		box->tr->start->x = ((xx - x) * box->tr->scale->x) + x;
		box->tr->start->y = ((yy - y) * box->tr->scale->y) + y;
	}
	return (0);
}

int			mse_rt_x(int button, int x, int y, t_container *box)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		box->tr->angle = 0.1;
		clear_tr_dr(box, rt_map_x);

	}
	if (button == 4)
	{
		box->tr->angle = -0.1;
		clear_tr_dr(box, rt_map_x);
	}
	if (button == 2)
	{
		mlx_mouse_hook(box->par->wn_ptr, mse_sc, box);
	}
	return (0);
}

int			mse_rt_y(int button, int x, int y, t_container *box)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		box->tr->angle = 0.1;
		clear_tr_dr(box, rt_map_y);

	}
	if (button == 4)
	{
		box->tr->angle = -0.1;
		clear_tr_dr(box, rt_map_y);
	}
	if (button == 2)
	{
		mlx_mouse_hook(box->par->wn_ptr, mse_sc, box);
	}
	return (0);
}

int			mse_rt_z(int button, int x, int y, t_container *box)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		box->tr->angle = 0.1;
		clear_tr_dr(box, rt_map_z);

	}
	if (button == 4)
	{
		box->tr->angle = -0.1;
		clear_tr_dr(box, rt_map_z);
	}
	if (button == 2)
	{
		mlx_mouse_hook(box->par->wn_ptr, mse_sc, box);
	}
	return (0);
}