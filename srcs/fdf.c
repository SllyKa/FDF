/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:16:52 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 10:41:46 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int			main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx");
	color = 255;
	color = color << 4;
	mlx_pixel_put(mlx_ptr, win_ptr, 149, 150, color);
	mlx_pixel_put(mlx_ptr, win_ptr, 151, 150, color);
	mlx_pixel_put(mlx_ptr, win_ptr, 150, 150, color);
	mlx_pixel_put(mlx_ptr, win_ptr, 150, 149, color);
	mlx_pixel_put(mlx_ptr, win_ptr, 150, 151, color);
	mlx_loop(mlx_ptr);

	return (0);
}