/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:29:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 18:58:48 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static void	poww(int *base)
{
	int i;

	i = 0;
	*base = 1;
	while (i < 6)
	{
		*base *= 16;
		i++;
	}
}

static int	chk_base(char *pntr, int *base, int *clr)
{
	if (*pntr >= '0' && *pntr <= '9')
	{
		*clr += (*pntr - 48) * *base;
		*base = *base / 16;
	}
	else if (*pntr >= 'A' && *pntr <= 'F')
	{
		*clr += (*pntr - 55) * *base;
		*base = *base / 16;
	}
	else
		return (-1);
	return (0);
}

static int	get_hex(char *pntr, int *color)
{
	int		i;
	int		clr;
	int		base;

	i = 0;
	clr = 0;
	poww(&base);
	pntr++;
	if (*pntr != '\0' && *(pntr + 1) != '\0' && *pntr == '0' && *(pntr + 1) == 'x')
	{
		pntr = pntr + 2;
			while (i < 6 && *pntr)
			{
				if (chk_base(pntr, &base, &clr))
					return (-1);
				i++;
				pntr++;
			}
	}
	if (*pntr != '\0')
		return (-1);
	*color = clr;
	return (0);
}

static int	zet_proc(char **tab, int *z, int *color)
{
	int				er;
	char			*pntr;

	er = 0;
	pntr = NULL;
	*z = ft_psatoi(*tab, &er, &pntr);
	if (*z > 3000)
		*z = 3000;
	else if (*z < -3000)
		*z = -3000;
	if (er < 0)
	{
		if (er == -2 && *pntr == ',')
		{
			if (!get_hex(pntr, color))
				return (0);
		}
		return (-1);
	}
	return (0);
}

t_pix_lst	*create_pxline(char **tab, int y, int color)
{
	int				x;
	int				z;
	t_pix_lst		*px_h;
	t_pointz		*ptz;
	int				cl;

	x = 0;
	px_h = NULL;
	while (*tab)
	{
		cl = color;
		if (zet_proc(tab, &z, &cl) < 0)
		{
			free_pxlst(px_h);
			return (NULL);
		}
		if (!(ptz = init_tpointz(x, y, z, cl)))
			return (NULL);
		if (!(px_h = add_px_lst(&px_h, ptz)))
			return (NULL);
		tab++;
		x++;
	}
	return (px_h);
}
