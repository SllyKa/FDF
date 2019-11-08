/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:27:01 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:37:24 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_btree_search(t_btree *root, void *data_ref)
{
	if (!root || !data_ref)
		return (NULL);
	if (root->left)
		return (ft_btree_search(root->left, data_ref));
	if (!(ft_strcmp(root->data, data_ref)))
		return (root->data);
	if (root->right)
		return (ft_btree_search(root->right, data_ref));
	return (0);
}
