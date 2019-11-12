/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:33:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 11:40:40 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <unistd.h>

void		free_pxlst(t_pix_lst * pxl)
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