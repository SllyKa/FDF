/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:28:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/11 07:54:38 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int			mouz(int button, int x, int y, t_container *box)
{
	ft_printf("button: %d\n", button);
	ft_printf("x: %d\n", x);
	ft_printf("y: %d\n", y);
	if (button == 5)
	{
		box->tr->scale->x += box->tr->scale->x * 0.1;
		box->tr->scale->y += box->tr->scale->y * 0.1;
		box->tr->scale->z += box->tr->scale->z * 0.1;
		mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
		fdf_sc_map(box->map, box->tr);
		fdf_draw_map(box->par, box->map, box->tr);
	}
	if (button == 4)
	{
		box->tr->scale->x -= box->tr->scale->x * 0.1;
		box->tr->scale->y -= box->tr->scale->y * 0.1;
		box->tr->scale->z -= box->tr->scale->z * 0.1;
		mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
		fdf_sc_map(box->map, box->tr);
		fdf_draw_map(box->par, box->map, box->tr);
	}
	(void)box;
	return (0);
}

int         keyz(int key, t_container *box)
{
	if (key == 53)
	{
		mlx_destroy_window(box->par->mx_ptr, box->par->wn_ptr);
		exit(0);
	}
	if (key == 123)
	{
		box->tr->scale->y += 10;
		mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
		fdf_draw_map(box->par, box->map, box->tr);
	}
	if (key == 124)
	{
		box->tr->scale->y -= 10;
		mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
		fdf_draw_map(box->par, box->map, box->tr);
	}
	if (key == 125)
	{
		box->tr->start->x += 10;
		mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
		fdf_draw_map(box->par, box->map, box->tr);
	}
	if (key == 126)
	{
		box->tr->start->x -= 10;
		mlx_clear_window(box->par->mx_ptr, box->par->wn_ptr);
		fdf_draw_map(box->par, box->map, box->tr);
	}
	
    //ft_printf("%d\n", key);
    return (0);
}

int			main(int argc, char **argv)
{
	int			fd;
	int			color;
	t_bilist	*map;
	t_window	*box;
	t_transfrm	*tr;
	t_container	*cntr;

	fd = fdf_arg_process(argc, argv);
	color = make_clr(0, 255, 0);
	map = fdf_parsing(fd, color);
	if (!(box = init_tcont(1000, 1000, "mlx")))
		return (-1);
	tr = init_transfrm(init_tpointz(500, 300, 200, 0), init_tpointz(30, 10, 10, 0));
	fdf_sc_map(map, tr);
	fdf_draw_map(box, map, tr);
	cntr = init_container(box, map, tr);
	mlx_key_hook(box->wn_ptr, keyz, cntr);
	mlx_mouse_hook(box->wn_ptr, mouz, cntr);
	mlx_loop(box->mx_ptr);
	return (0);
}