/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constructors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:59:45 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 16:05:42 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_cont		*init_tcont(void *a, void *b)
{
	t_cont		*new;

	if (!(new = (t_cont*)malloc(sizeof(t_cont))))
		return (NULL);
	new->mx_ptr = a;
	new->wn_ptr = b;
	return (new);
}