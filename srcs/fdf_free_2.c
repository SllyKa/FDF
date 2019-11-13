/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:33:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/13 15:49:05 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

static int	check_oneline(t_bilist **pxar)
{
	if (!pxar || !(*pxar))
		return (-1);
	if (!((*pxar)->head))
	{
		if ((*pxar)->data)
			free_pxlst((*pxar)->data);
		free(*pxar);
		return (-1);
	}
	else
		*pxar = (*pxar)->head;
	return (0);
}

void		free_sbilist(t_bilist **pxar)
{
	t_pix_lst		*plxlst;
	t_pix_lst		*plxtemp;
	t_bilist		*tmp;

	if (check_oneline(pxar) < 0)
		return ;
	while (*pxar)
	{
		plxlst = (*pxar)->data;
		plxlst = plxlst->head;
		while (plxlst)
		{
			if (plxlst->data)
				free(plxlst->data);
			plxtemp = plxlst;
			plxlst = plxlst->next;
			free(plxtemp);
		}
		tmp = *pxar;
		*pxar = (*pxar)->next;
		free(tmp);
		tmp = NULL;
	}
	*pxar = NULL;
}
