/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:16:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/10 16:28:01 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

int         keyz(int key, t_window *box)
{
	if (key == 53)
	{
		mlx_destroy_window(box->mx_ptr, box->wn_ptr);
		exit(0);
	}
    ft_putnbr(key);
    return (0);
}

int			main(void)
{
	int			color;
	t_window	*box;
	t_point		*p0;
	t_point		*p1;
	t_line		*line;

	box = init_tcont(NULL, NULL);
	if (!(box->mx_ptr = mlx_init()))
		return (-1);
	if (!(box->wn_ptr = mlx_new_window(box->mx_ptr, 500, 500, "mlx")))
		return (-1);
	color = make_clr(0, 255, 0);

	p0 = init_tpoint(0, 0, color);
	p1 = init_tpoint(500, 500, color);
	if (!p0 || !p1)
		return (0);
	if (!(line = init_tline(p0, p1)))
		return (0);
	draw_line_bres(box, line);

	line->p0->x=0;
	line->p0->y=0;
	line->p1->x=499;
	line->p1->y=0;
	draw_line_bres(box, line);

	line->p0->x=499;
	line->p0->y=0;
	line->p1->x=499;
	line->p1->y=499;
	draw_line_bres(box, line);

	line->p0->x=499;
	line->p0->y=499;
	line->p1->x=0;
	line->p1->y=499;
	draw_line_bres(box, line);

	line->p0->x=0;
	line->p0->y=499;
	line->p1->x=0;
	line->p1->y=0;
	draw_line_bres(box, line);

	line->p0->x=250;
	line->p0->y=0;
	line->p1->x=280;
	line->p1->y=499;
	draw_linew(box, line);

	line->p0->x=280;
	line->p0->y=0;
	line->p1->x=310;
	line->p1->y=499;
	draw_line_bres(box, line);

	/*line->p0->x=0;
	line->p0->y=250;
	line->p1->x=499;
	line->p1->y=280;
	draw_line_bres(box, line);

	line->p0->x=250;
	line->p0->y=245;
	line->p1->x=250;
	line->p1->y=255;
	draw_linew(box, line);*/

	mlx_key_hook(box->wn_ptr, keyz, box);
	mlx_loop(box->mx_ptr);

	return (0);
}