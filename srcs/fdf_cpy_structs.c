/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cpy_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:09:54 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 14:08:12 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bilist	*init_tpixlstar(t_bilist *pix_lst, t_pix_lst *data)
{
	t_bilist	*new_pix_ar;

	if (!(new_pix_ar = init_bilist(NULL, 0)))
		return (NULL);
	new_pix_ar->data = data;
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
			return (NULL);
		new_pix_ar->head = pix_lst->head;
		new_pix_ar->prev = pix_lst;
		pix_lst->next = new_pix_ar;
		pix_lst = new_pix_ar;
	}
	return (pix_lst);
}

t_bilist		*cpy_map(t_bilist *srcs)
{
	t_bilist	*cpy;
	t_pix_lst	*pxl;
	t_pix_lst	*pxl_cpy;
	t_pointz	*ptz_cpy;

	cpy = NULL;
	while (srcs)
	{
		pxl = srcs->data;
		pxl_cpy = NULL;
		while (pxl)
		{
			if (!(ptz_cpy = init_tpointz(pxl->data->x, pxl->data->y,
			pxl->data->z, pxl->data->clr)))
				return (NULL);
			if (!(pxl_cpy = add_px_lst(&pxl_cpy, ptz_cpy)))
				return (NULL);
			pxl = pxl->next;
		}
		cpy = init_tpixlstar(cpy, pxl_cpy);
		srcs = srcs->next;
	}
	return (cpy->head);
}
