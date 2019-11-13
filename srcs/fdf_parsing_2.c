/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:29:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/13 15:12:30 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static int	pars_hex(char *pntr, int *clr)
{
	char	*hex;
	int		i;

	i = 0;
	if (!(hex = (char*)malloc(sizeof(char) * 9)))
		exit(0);
	while (*pntr)
	{
		if (i >= 8)
			return (-1);
		if (!((*pntr >= '0' && *pntr <= '9') ||
		(*pntr >= 'A' && *pntr <= 'F') || (*pntr >= 'a' && *pntr <= 'f')))
			return (-1);
		hex[i] = *pntr;
		hex[i + 1] = '\0';
		i++;
		pntr++;
	}
	if (ft_hextodec(hex, clr) < 0)
		return (-1);
	return (0);
}

static int	get_hex(char *pntr, int *color)
{
	int		clr;

	clr = 0;
	pntr++;
	if (*pntr != '\0' && *(pntr + 1) != '\0' &&
	*pntr == '0' && *(pntr + 1) == 'x')
	{
		pntr = pntr + 2;
		if (pars_hex(pntr, &clr) < 0)
			return (-1);
		*color = clr;
	}
	else
		return (-1);
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
