/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyz_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 06:30:01 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:21:53 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

static void		keyz_2(int key, t_container *box)
{
	if (key == 15)
	{
		reset_map(box);
		fdf_draw_map(box->par, box->map);
	}
	if (key == 34)
	{
		reset_map(box);
		box->tr->angle = 0.523599;
		clear_tr_dr(box, iso_map);
	}
}

int				keyz(int key, t_container *box)
{
	if (key == 53)
	{
		mlx_destroy_window(box->par->mx_ptr, box->par->wn_ptr);
		free(box->par->mx_ptr);
		free_cntner(box);
		exit(0);
	}
	if (key == 7)
		mlx_mouse_hook(box->par->wn_ptr, mse_rt_x, box);
	if (key == 0)
		mlx_mouse_hook(box->par->wn_ptr, mse_rt_y, box);
	if (key == 6)
		mlx_mouse_hook(box->par->wn_ptr, mse_rt_z, box);
	if (key == 12)
		mlx_mouse_hook(box->par->wn_ptr, mse_mv_x, box);
	if (key == 13)
		mlx_mouse_hook(box->par->wn_ptr, mse_mv_y, box);
	if (key == 1)
		mlx_mouse_hook(box->par->wn_ptr, mse_mv_z, box);
	if (key == 15 || key == 34)
		keyz_2(key, box);
	return (0);
}
