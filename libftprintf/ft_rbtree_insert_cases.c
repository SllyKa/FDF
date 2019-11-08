/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_insert_cases.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:09:27 by lshanaha          #+#    #+#             */
/*   Updated: 2019/02/04 15:16:40 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

/*
** Процедура установки нового узла в конкретное, выбранное ранее место в дереве
** Текущий узел N в корне дерева. В этом случае, он перекрашивается в чёрный
** цвет
*/

void	ft_insert_case1(t_rb_node *n)
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		ft_insert_case2(n);
}

/*
** Если не корень, то едем ко 2 случаю
** Предок P текущего узла чёрный
*/

void	ft_insert_case2(t_rb_node *n)
{
	if (n->parent->color == BLACK)
		return ;
	else
		ft_insert_case3(n);
}

/*
** Eсли предок текущего узла черный, то все хорошо, если красный, то едем
** дальше.
** Если и родитель P и дядя U — красные, то они оба могут быть перекрашены в
** чёрный и дедушка G станет красным
** (n->parent->color == RED) Второе условие проверяется в insert_case2,
** то есть родитель уже является красным.
*/

void	ft_insert_case3(t_rb_node *n)
{
	t_rb_node *u;
	t_rb_node *g;

	u = ft_uncle(n);
	if ((u != NULL) && (u->color == RED))
	{
		n->parent->color = BLACK;
		u->color = BLACK;
		g = ft_grandparent(n);
		g->color = RED;
		ft_insert_case1(g);
	}
	else
		ft_insert_case4(n);
}

/*
** Если удалось перекрасить дядю, родителя и корень, при этом не потребовалось
** перерабатывать ранние значения, то заканчиваем, если дядя черный, то едем
** дальше. Если требуется переработка конфигурации для деда, то передаем его
** на шаг 1.
** Родитель P является красным, но дядя U — чёрный. Также, текущий узел N —
** правый потомок P, а P в свою очередь — левый потомок своего предка G
*/

void	ft_insert_case4(t_rb_node *n)
{
	t_rb_node *g;

	g = ft_grandparent(n);
	if ((n == n->parent->right) && (n->parent == g->left))
	{
		ft_rotate_left(n->parent);
		n = n->left;
	}
	else if ((n == n->parent->left) && (n->parent == g->right))
	{
		ft_rotate_right(n->parent);
		n = n->right;
	}
	ft_insert_case5(n);
}

/*
** так или иначе потребуется отправится на шаг 5, т.к. данное преобразование
** переставляет местами родителя и потомка без перекраски и проверки на
** корректность цветов
** Родитель P является красным, но дядя U — чёрный, текущий узел N — левый
** потомок P и P — левый потомок
*/

void	ft_insert_case5(t_rb_node *n)
{
	t_rb_node *g;

	g = ft_grandparent(n);
	n->parent->color = BLACK;
	g->color = RED;
	if ((n == n->parent->left) && (n->parent == g->left))
		ft_rotate_right(g);
	else
		ft_rotate_left(g);
}
