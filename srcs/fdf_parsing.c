/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:23:26 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:49:22 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include <unistd.h>

t_pix_lst			*add_px_lst(t_pix_lst **px_h, t_pointz *ptz)
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

static t_bilist		*fill_tpixstarend(t_bilist *pix_lst,
t_bilist *new_pix_ar)
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
	return (pix_lst);
}

static t_bilist		*init_tpixlstar(t_bilist *pix_lst,
char **tab, int y, int color)
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
		if (!(pix_lst = fill_tpixstarend(pix_lst, new_pix_ar)))
			return (NULL);
	}
	return (pix_lst);
}

static void			error_parsing_prcsing(char **tab, char *line, int fd)
{
	free_tab(tab);
	free(line);
	while (get_next_line(fd, &line) > 0)
		free(line);
	close(fd);
	exit(0);
}

t_bilist			*fdf_parsing(int fd, int color, int *y)
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
			error_parsing_prcsing(tab, line, fd);
		free_tab(tab);
		free(line);
		line = NULL;
		(*y)++;
	}
	if (er < 0)
		free(line);
	return (pixar);
}
