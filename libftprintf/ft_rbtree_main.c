/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:10:59 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:51:45 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

t_rb_node	*ft_create_node(int num, char *text, t_rb_node *parent)
{
	t_rb_node *node;

	node = (t_rb_node *)malloc(sizeof(t_rb_node));
	if (!node)
		return (0);
	node->data = num;
	node->text = text;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->color = RED;
	return (node);
}

t_rb_node	*ft_add_in_tree(t_rb_node **root, int data, char *text)
{
	t_rb_node *node;
	t_rb_node *parent;

	node = *root;
	parent = NULL;
	while (node != NULL)
		if (node->data > data)
		{
			parent = node;
			node = node->left;
		}
		else if (node->data < data)
		{
			parent = node;
			node = node->right;
		}
		else if (node->data == data)
			return (ft_find_root(node));
	node = ft_create_node(data, text, parent);
	(parent && parent->data > data) ? parent->left = node : node;
	(parent && parent->data < data) ? parent->right = node : node;
	ft_insert_case1(node);
	*root = ft_find_root(node);
	return (*root);
}

void		ft_treeprint(t_rb_node *p)
{
	if (p != NULL)
	{
		ft_treeprint(p->left);
		ft_putnbr(p->data);
		ft_putstr(" ");
		ft_putstr(p->text);
		if (p->color == 0)
			ft_putstr(" Black\n");
		else
			ft_putstr(" Red\n");
		ft_treeprint(p->right);
	}
}

t_rb_node	*ft_findnode_text(t_rb_node *root, char *text)
{
	t_rb_node *temp;

	temp = root;
	while (temp != NULL)
		if (EQ(text, temp->text))
			return (temp);
		else
			temp = DIFF(text, temp->text) ? temp->left : temp->right;
	return (NULL);
}

t_rb_node	*ft_findnode_data(t_rb_node *root, int data)
{
	t_rb_node *temp;

	temp = root;
	while (temp != NULL)
		if (data == temp->data)
			return (temp);
		else
			temp = (data - temp->data < 0) ? temp->left : temp->right;
	return (NULL);
}
