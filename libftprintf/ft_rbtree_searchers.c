/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_searchers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:54:00 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/04 15:19:49 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

/*
** поиск дедушки вставляемого узла
*/

t_rb_node	*ft_grandparent(t_rb_node *n)
{
	if ((n != NULL) && (n->parent != NULL))
		return (n->parent->parent);
	else
		return (NULL);
}

/*
** поиск дяди (брата родителя) вставляемого узла
*/

t_rb_node	*ft_uncle(t_rb_node *n)
{
	t_rb_node *g;

	g = ft_grandparent(n);
	if (g == NULL)
		return (NULL);
	if (n->parent == g->left)
		return (g->right);
	else
		return (g->left);
}
