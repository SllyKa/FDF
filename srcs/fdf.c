/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:16:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 16:21:35 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libftprintf.h"
#include "fdf.h"

int         keyz(int key, t_cont *box)
{
	if (key == 53)
		mlx_destroy_window(box->mx_ptr, box->wn_ptr);
    ft_putnbr(key);
    return (0);
}

int			main(void)
{
	int		color;
	t_cont	*box;

	box = init_tcont(NULL, NULL);
	if (!(box->mx_ptr = mlx_init()))
		return (-1);
	if (!(box->wn_ptr = mlx_new_window(box->mx_ptr, 500, 500, "mlx")))
		return (-1);
	color = 255;
	color = color << 4;
	mlx_pixel_put(box->mx_ptr, box->wn_ptr, 149, 150, color);
	mlx_pixel_put(box->mx_ptr, box->wn_ptr, 151, 150, color);
	mlx_pixel_put(box->mx_ptr, box->wn_ptr, 150, 150, color);
	mlx_pixel_put(box->mx_ptr, box->wn_ptr, 150, 149, color);
	mlx_pixel_put(box->mx_ptr, box->wn_ptr, 150, 151, color);
	mlx_key_hook(box->wn_ptr, keyz, box);
	mlx_loop(box->mx_ptr);

	return (0);
}