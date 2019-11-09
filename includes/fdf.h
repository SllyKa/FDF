/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:26:06 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/09 20:53:13 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "math.h"
# include "libftprintf.h"

typedef struct	s_window
{
	void	*mx_ptr;
	void	*wn_ptr;
}				t_window;

typedef struct	s_point
{
	int		x;
	int		y;
	int 	clr;
}				t_point;

typedef struct	s_line
{
	t_point	*p0;
	t_point	*p1;
}				t_line;

t_window		*init_tcont(void *a, void *b);
t_point			*init_tpoint(int x, int y, int clr);
t_line			*init_tline(t_point *p0, t_point *p1);
int				make_clr(unsigned char r, unsigned char g, unsigned char b);
int				make_a_clr(int clr, float a);
void			draw_line_bres(t_window *par, t_line *fline);
void			put_px(t_window *par, t_point *p, char b);
void			draw_linew(t_window *par, t_line *line);

#endif