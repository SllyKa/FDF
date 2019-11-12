/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mse_hooks_mv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:57:00 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:22:54 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int			mse_mv_x(int button, int x, int y, t_container *box)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		val_to_ptz(box->tr->mvstep, 70, 0, 0);
		box->tr->start->x += 70;
		clear_tr_dr(box, mv_map);
	}
	if (button == 4)
	{
		val_to_ptz(box->tr->mvstep, -70, 0, 0);
		box->tr->start->x -= 70;
		clear_tr_dr(box, mv_map);
	}
	if (button == 2)
		mlx_mouse_hook(box->par->wn_ptr, mse_sc, box);
	return (0);
}

int			mse_mv_y(int button, int x, int y, t_container *box)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		val_to_ptz(box->tr->mvstep, 0, 70, 0);
		box->tr->start->y += 70;
		clear_tr_dr(box, mv_map);
	}
	if (button == 4)
	{
		val_to_ptz(box->tr->mvstep, 0, -70, 0);
		box->tr->start->y -= 70;
		clear_tr_dr(box, mv_map);
	}
	if (button == 2)
		mlx_mouse_hook(box->par->wn_ptr, mse_sc, box);
	return (0);
}

int			mse_mv_z(int button, int x, int y, t_container *box)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		val_to_ptz(box->tr->mvstep, 0, 0, 70);
		box->tr->start->z += 70;
		clear_tr_dr(box, mv_map);
	}
	if (button == 4)
	{
		val_to_ptz(box->tr->mvstep, 0, 0, -70);
		box->tr->start->z -= 70;
		clear_tr_dr(box, mv_map);
	}
	if (button == 2)
		mlx_mouse_hook(box->par->wn_ptr, mse_sc, box);
	return (0);
}
