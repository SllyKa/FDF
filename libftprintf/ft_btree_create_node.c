/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:17:58 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:37:16 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

t_btree	*ft_btree_create_node(void *item)
{
	t_btree *node;

	if (item == NULL)
		return (0);
	node = (t_btree *)malloc(sizeof(t_btree));
	if (node == NULL)
		return (0);
	node->data = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
