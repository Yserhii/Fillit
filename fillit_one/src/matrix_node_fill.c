/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_node_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:20:03 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:19:39 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_create_node_all_var(int *tab, t_matrix *pmatrix, int letter)
{
	int			i;
	static int	y = 1;
	t_matrix	*head;
	t_matrix	*col;
	t_matrix	*back;

	i = -1;
	while (pmatrix->x != letter)
		pmatrix = pmatrix->right;
	head = pmatrix;
	pmatrix = pmatrix->up;
	ft_node_var(pmatrix, head, y);
	pmatrix = pmatrix->down;
	col = head;
	back = pmatrix;
	while (tab[++i] && i <= 3)
	{
		while (tab[i] != col->x)
			col = col->right;
		head = col;
		head = head->up;
		back = back->right;
		back->right = ft_node_elem(pmatrix, head, col, back);
	}
	y++;
}

t_matrix	*ft_node_fill(t_matrix *left, t_matrix *right, int x, int y)
{
	t_matrix		*tmp;

	if (!(tmp = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	tmp->up = tmp;
	tmp->down = tmp;
	tmp->left = left;
	tmp->right = right;
	tmp->column = tmp;
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

t_matrix	*ft_node_elem(t_matrix *pmatrix, t_matrix *head,
							t_matrix *col, t_matrix *back)
{
	t_matrix	*tmp;

	if (!(tmp = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return (NULL);
	tmp->up = head;
	tmp->down = col;
	tmp->column = col;
	tmp->left = back;
	tmp->right = pmatrix;
	tmp->x = col->x;
	tmp->y = pmatrix->y;
	col->up = tmp;
	head->down = tmp;
	pmatrix->left = tmp;
	return (tmp);
}

void		ft_node_var(t_matrix *pmatrix, t_matrix *head, int y)
{
	t_matrix	*tmp;

	if (!(tmp = (t_matrix*)ft_memalloc(sizeof(t_matrix))))
		return ;
	tmp->up = pmatrix;
	tmp->down = head;
	tmp->column = head;
	tmp->right = tmp;
	tmp->left = tmp;
	tmp->x = head->x;
	tmp->y = y;
	head->up = tmp;
	pmatrix->down = tmp;
}
