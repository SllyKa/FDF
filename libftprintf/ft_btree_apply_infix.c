/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:21:02 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:36:52 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || applyf == NULL)
		return ;
	if (root->left)
		ft_btree_apply_infix(root->left, (applyf));
	(applyf)(root->data);
	if (root->right)
		ft_btree_apply_infix(root->right, applyf);
}
