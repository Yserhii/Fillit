/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:21:30 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:18:29 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_lstfree(t_list **lst)
{
	t_list		*next;
	t_list		*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
}

static void		ft_nodefree(t_matrix *node)
{
	node->up = NULL;
	node->down = NULL;
	node->right = NULL;
	node->up = NULL;
	node->column = NULL;
	free(node);
}

void			ft_matrixfree(t_matrix *head)
{
	t_matrix	*col;
	t_matrix	*node;

	while (head->right != head && (col = head->right))
	{
		col->left->right = col->right;
		col->right->left = col->left;
		while (col->down != col && (node = col->down))
		{
			node->up->down = node->down;
			node->down->up = node->up;
			ft_nodefree(node);
		}
		ft_nodefree(col);
	}
	ft_nodefree(head);
}
