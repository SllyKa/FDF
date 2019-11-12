/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:23:26 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 12:34:17 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

t_pix_lst	*add_px_lst(t_pix_lst **px_h, t_pointz *ptz)
{
	t_pix_lst	*new_px_lst;

	if (!px_h)
		return (NULL);
	if (!(new_px_lst = init_tpxlist(ptz)))
	{
		free(ptz);
		return (NULL);
	}
	if (!(*px_h))
	{
		*px_h = new_px_lst;
		(*px_h)->head = new_px_lst;
	}
	else
	{
		new_px_lst->head = (*px_h)->head;
		(*px_h)->next = new_px_lst;
		*px_h = new_px_lst;
	}
	return (*px_h);
}

static t_pix_lst	*create_pxline(char **tab, int y, int color)
{
	int				x;
	int				z;
	int 			er;
	t_pix_lst		*px_h;
	t_pointz		*ptz;

	x = 0;
	er = 0;
	px_h = NULL;
	while (*tab)
	{
		z = ft_satoi(*tab, &er);
		if (z > 3000)
			z = 3000;
		else if (z < -3000)
			z = -3000;
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

static t_bilist	*init_tpixlstar(t_bilist *pix_lst, char **tab, int y, int color)
{
	t_bilist		*new_pix_ar;

	if (!(new_pix_ar = init_bilist(NULL, 0)))
		return (NULL);
	if (!(new_pix_ar->data = create_pxline(tab, y, color)))
	{
		free_sbilist(&new_pix_ar);
		free_sbilist(&pix_lst);
		return (NULL);
	}
	new_pix_ar->s = new_pix_ar->data->data->x;
	new_pix_ar->data = new_pix_ar->data->head;
	if (!pix_lst)
	{
		pix_lst = new_pix_ar;
		pix_lst->head = pix_lst;
	}
	else
	{
		if (pix_lst->s != new_pix_ar->s)
		{
			free_sbilist(&new_pix_ar);
			free_sbilist(&pix_lst);
			return (NULL);
		}
		new_pix_ar->head = pix_lst->head;
		new_pix_ar->prev = pix_lst;
		pix_lst->next = new_pix_ar;
		pix_lst = new_pix_ar;
	}
	return (pix_lst);
}

t_bilist		*fdf_parsing(int fd, int color, int *y)
{
	int			er;
	char		*line;
	char		**tab;
	t_bilist	*pixar;

	*y = 0;
	line = NULL;
	pixar = NULL;
	while ((er = get_next_line(fd, &line)) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (!(pixar = init_tpixlstar(pixar, tab, *y, color)))
		{
			free_tab(tab);
			free(line);
			line = NULL;
			while (get_next_line(fd, &line) > 0)
				free(line);
			exit (0);
		}
		free_tab(tab);
		free(line);
		line = NULL;
		(*y)++;
	}
	if (er < 0)
		free(line);
	return (pixar);
}