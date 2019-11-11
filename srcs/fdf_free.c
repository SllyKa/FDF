/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:11:50 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/11 03:56:04 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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

void	free_sbilist(t_bilist **pxar)
{
	t_pix_lst		*plxlst;
	t_bilist		*tmp;

	*pxar = (*pxar)->head;
	while(*pxar)
	{
		plxlst = (*pxar)->data;
		while(plxlst)
		{
			free(plxlst->data);
			free(plxlst);
			plxlst = plxlst->next;
		}
		tmp = *pxar;
		*pxar = (*pxar)->next;
		free(tmp);
		tmp = NULL;
	}
	*pxar = NULL;
}

void	free_line(t_line *lne)
{
	if (!lne)
		return ;
	if (lne->p0)
		free(lne->p0);
	if(lne->p1)
		free(lne->p1);
	if(lne->pp0)
		free(lne->pp0);
	if(lne->pp1)
		free(lne->pp1);
	free(lne);
}