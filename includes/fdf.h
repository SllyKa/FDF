/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:26:06 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:30:15 by gbrandon         ###   ########.fr       */
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

typedef struct	s_pointz
{
	double			x;
	double			y;
	double			z;
	int				clr;
}				t_pointz;

typedef struct	s_pix_lst
{
	t_pointz			*data;
	struct s_pix_lst	*head;
	struct s_pix_lst	*next;
}				t_pix_lst;

typedef struct	s_bilist
{
	t_pix_lst			*data;
	size_t				s;
	struct s_bilist		*next;
	struct s_bilist		*prev;
	struct s_bilist		*head;
}				t_bilist;

typedef struct	s_line
{
	t_pointz	*p0;
	t_pointz	*p1;
	t_point		*pp0;
	t_point		*pp1;
}				t_line;

typedef struct s_transfrm
{
	t_pointz	*start;
	t_pointz	*scale;
	t_pointz	*mvstep;
	double		angle;
	t_bilist	*map_cpy;
}				t_transfrm;

typedef struct	s_container
{
	t_window	*par;
	t_bilist	*map;
	t_transfrm	*tr;
	double		y;
}				t_container;



t_window		*init_tcont(int x, int y, char *name);
t_point			*init_tpoint(int x, int y, int clr);
t_pointz		*init_tpointz(double x, double y, double z, int clr);
t_line			*init_tline(t_pointz *p0, t_pointz *p1);
t_pix_lst		*init_tpxlist(t_pointz *pntz);
t_bilist		*init_bilist(t_pix_lst *px_lst, size_t s);
t_transfrm		*init_transfrm(t_pointz *st, t_pointz *scale,
t_pointz *mvstep, double angle);
t_container		*init_container(t_window *par, t_bilist *map,
t_transfrm *tr, double y);

int				make_clr(unsigned char r, unsigned char g, unsigned char b);
int				make_a_clr(int clr, double a);
void			draw_line_bres(t_window *par, t_line *fline);
void			put_px(t_window *par, t_point *p, char b);
void			draw_linew(t_window *par, t_line *line);
int				fdf_arg_process(int argc, char **argv, int *color);
t_bilist		*fdf_parsing(int fd, int color, int *y);
void			fdf_draw_map(t_window *par, t_bilist *map);
t_line			*fill_line(t_pointz *p0, t_pointz *p1);
void			fswap(double *a, double *b);
void			fdf_map_trnsf(t_bilist *map, t_transfrm *tr,
void (*f_ptr)(t_pointz *, t_transfrm *));
void			mv_map(t_pointz *p0, t_transfrm *tr);
void			sc_map(t_pointz *p0, t_transfrm *tr);
void			rt_map_x(t_pointz *p0, t_transfrm *tr);
void			rt_map_y(t_pointz *p0, t_transfrm *tr);
void			rt_map_z(t_pointz *p0, t_transfrm *tr);
t_bilist		*cpy_map(t_bilist *srcs);
t_pix_lst		*add_px_lst(t_pix_lst **px_h, t_pointz *ptz);
void			val_to_ptz(t_pointz *p0, double valx,
double valy, double valz);
void			clear_tr_dr(t_container *box,
void (*f)(t_pointz *, t_transfrm *));
void			iso_map(t_pointz *p0, t_transfrm *tr);
int				keyz(int key, t_container *box);
t_transfrm		*start_map(t_bilist *map, double y);
void			reset_map(t_container *box);
void			put_bold_px(t_window *par, int x, int y, int clr);
t_pix_lst		*create_pxline(char **tab, int y, int color);

int				mse_sc(int button, int x, int y, t_container *box);
int				mse_rt_x(int button, int x, int y, t_container *box);
int				mse_rt_y(int button, int x, int y, t_container *box);
int				mse_rt_z(int button, int x, int y, t_container *box);
int				mse_mv_x(int button, int x, int y, t_container *box);
int				mse_mv_y(int button, int x, int y, t_container *box);
int				mse_mv_z(int button, int x, int y, t_container *box);

void			free_tab(char **tab);
void			free_sbilist(t_bilist **pxar);
void			free_line(t_line *lne);
void			free_stransfrm(t_transfrm **tr);
void			free_cntner(t_container	*box);
void			free_pxlst(t_pix_lst * pxl);

#endif