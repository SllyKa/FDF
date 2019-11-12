/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:28:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 13:46:22 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fdf.h"

static int		init_map(int fd, t_container **cntr, int color)
{
	int			y;
	t_bilist	*map;
	t_window	*box;
	t_transfrm	*tr;

	color = (color ? color : make_clr(0, 255, 0));
	y = 0;
	if (!(map = fdf_parsing(fd, color, &y)))
		return (-1);
	map = map->head;
	if (!(box = init_tcont(1600, 1200, "mlx")))
		return (-1);
	if ((map->s == 0) && (y == 1))
		put_bold_px(box, map->data->data->x,
		map->data->data->y, map->data->data->clr);
	tr = start_map(map, y);
	tr->angle = 0.523599;
	*cntr = init_container(box, map, tr, y);
	clear_tr_dr(*cntr, iso_map);
	return (0);
}

int				main(int argc, char **argv)
{
	int			color;
	int			fd;
	t_container	*cntr;

	color = 0;
	fd = fdf_arg_process(argc, argv, &color);
	if (init_map(fd, &cntr, color) < 0)
		return (-1);
	close(fd);
	mlx_key_hook(cntr->par->wn_ptr, keyz, cntr);
	mlx_mouse_hook(cntr->par->wn_ptr, mse_sc, cntr);
	mlx_loop(cntr->par->mx_ptr);
	return (0);
}
