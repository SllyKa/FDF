/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:09:10 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/04 15:13:47 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void		ft_rotate_left(t_rb_node *n)
{
	t_rb_node *pivot;

	pivot = n->right;
	pivot->parent = n->parent;
	if (n->parent != NULL)
	{
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}
	n->right = pivot->left;
	if (pivot->left != NULL)
		pivot->left->parent = n;
	n->parent = pivot;
	pivot->left = n;
}

void		ft_rotate_right(t_rb_node *n)
{
	t_rb_node *pivot;

	pivot = n->left;
	pivot->parent = n->parent;
	if (n->parent != NULL)
	{
		if (n->parent->left == n)
			n->parent->left = pivot;
		else
			n->parent->right = pivot;
	}
	n->left = pivot->right;
	if (pivot->right != NULL)
		pivot->right->parent = n;
	n->parent = pivot;
	pivot->right = n;
}

/*
** Функция удаления поддерева
*/

void		ft_freemem(t_rb_node *tree, t_rb_node *stop)
{
	if (tree != stop)
	{
		ft_freemem(tree->left, stop);
		ft_freemem(tree->right, stop);
		free(tree);
	}
}

t_rb_node	*ft_find_root(t_rb_node *node)
{
	while (node->parent != NULL)
		node = node->parent;
	return (node);
}
