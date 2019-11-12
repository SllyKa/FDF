/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:11:50 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:11:56 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

void	free_tab(char **tab)
{
	char	**h_tab;

	h_tab = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(h_tab);
	h_tab = NULL;
}

void	free_pxlst(t_pix_lst *pxl)
{
	t_pix_lst	*tmp;

	if (!pxl)
		return ;
	pxl = pxl->head;
	while (pxl)
	{
		if (pxl->data)
			free(pxl->data);
		tmp = pxl;
		pxl = pxl->next;
		free(tmp);
	}
}

void	free_cntner(t_container *box)
{
	if (!box)
		return ;
	if (box->par)
		free(box->par);
	if (box->tr)
	{
		if (box->tr->map_cpy)
			free_sbilist(&(box->tr->map_cpy));
		free_stransfrm(&(box->tr));
	}
	if (box->map)
		free_sbilist(&(box->map));
	free(box);
}

void	free_stransfrm(t_transfrm **tr)
{
	if (!tr || !(*tr))
		return ;
	if ((*tr)->start)
		free((*tr)->start);
	if ((*tr)->scale)
		free((*tr)->scale);
	if ((*tr)->mvstep)
		free((*tr)->mvstep);
	free(*tr);
}

void	free_line(t_line *lne)
{
	if (!lne)
		return ;
	if (lne->p0)
		free(lne->p0);
	if (lne->p1)
		free(lne->p1);
	if (lne->pp0)
		free(lne->pp0);
	if (lne->pp1)
		free(lne->pp1);
	free(lne);
}
