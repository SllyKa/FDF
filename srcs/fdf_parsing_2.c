/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:29:46 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:59:48 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

static int	zet_proc(char **tab, int *z, int *er)
{
	*z = ft_satoi(*tab, er);
	if (*z > 3000)
		*z = 3000;
	else if (*z < -3000)
		*z = -3000;
	return (0);
}

t_pix_lst	*create_pxline(char **tab, int y, int color)
{
	int				x;
	int				z;
	int				er;
	t_pix_lst		*px_h;
	t_pointz		*ptz;

	x = 0;
	er = 0;
	px_h = NULL;
	while (*tab)
	{
		zet_proc(tab, &z, &er);
		if (er < 0)
		{
			free_pxlst(px_h);
			return (NULL);
		}
		if (!(ptz = init_tpointz(x, y, z, color)))
			return (NULL);
		if (!(px_h = add_px_lst(&px_h, ptz)))
			return (NULL);
		tab++;
		x++;
	}
	return (px_h);
}
