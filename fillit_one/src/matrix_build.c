/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:19:18 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:19:00 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix		*ft_create_header(t_matrix **matrix, int x, int sidelen2)
{
	int				y;
	t_matrix		*pmatrix;
	t_matrix		*head;

	y = 0;
	pmatrix = *matrix;
	pmatrix = ft_node_fill(NULL, NULL, (x - 1), y);
	head = pmatrix;
	pmatrix->right = ft_node_fill(NULL, NULL, x, y);
	x++;
	while (x <= sidelen2)
	{
		while (pmatrix->right)
			pmatrix = pmatrix->right;
		pmatrix->right = ft_node_fill(pmatrix, NULL, x, y);
		x++;
	}
	pmatrix->right->right = head;
	head->left = pmatrix->right;
	head->right->left = head;
	return (head);
}

t_matrix			*ft_matrix_fill(t_list **lst, int count, int sidelen)
{
	t_list			*plst;
	t_matrix		*pmatrix;
	t_matrix		*head;
	int				letter;

	plst = *lst;
	letter = -count + 1;
	head = ft_create_header(&pmatrix, (1 - count), (sidelen * sidelen));
	pmatrix = head->right;
	while (plst)
	{
		ft_all_var_tab(plst, sidelen, pmatrix, letter);
		plst = plst->next;
		letter++;
	}
	return (head);
}
