/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cover_uncover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:03:02 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:18:16 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_uncover(t_matrix *curr)
{
	t_matrix	*col;
	t_matrix	*point;
	t_matrix	*point2;

	col = curr->column;
	col->left->right = col;
	col->right->left = col;
	point = curr->down;
	while (point->y != 0)
	{
		point2 = point;
		point2 = point2->right;
		while (point2 != point)
		{
			point2->down->up = point2;
			point2->up->down = point2;
			point2 = point2->right;
		}
		point2->down->up = point2;
		point2->up->down = point2;
		point = point->down;
	}
}

void		check_and_uncover(t_stack **res)
{
	t_matrix	*var;
	t_matrix	*col;
	t_stack		*tmp;

	var = (*res)->content;
	tmp = (*res)->next;
	free(*res);
	*res = tmp;
	col = var->column;
	col->left->right = col;
	col->right->left = col;
	var->up->down = var;
	var->down->up = var;
	while ((var = var->right) && var->x > 0)
	{
		ft_uncover(var);
		var->up->down = var;
		var->down->up = var;
	}
}

void		ft_stackadd(t_matrix *var, t_stack **res)
{
	t_stack		*tmp;

	if (!(tmp = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	tmp->content = var;
	tmp->next = *res;
	*res = tmp;
}

void		ft_cover(t_matrix *curr)
{
	t_matrix	*col;
	t_matrix	*point;
	t_matrix	*point2;

	col = curr->column;
	col->left->right = col->right;
	col->right->left = col->left;
	point = curr;
	point = point->down;
	while (point->y != 0)
	{
		point2 = point;
		point2 = point2->right;
		while (point2 != point)
		{
			point2->down->up = point2->up;
			point2->up->down = point2->down;
			point2 = point2->right;
		}
		point->down->up = point->up;
		point->up->down = point->down;
		point = point->down;
	}
}

void		choose_and_cover(t_matrix *var, t_stack **res)
{
	t_matrix	*col;
	t_matrix	*point;

	col = var->column;
	point = var;
	col->left->right = col->right;
	col->right->left = col->left;
	ft_stackadd(point, res);
	while ((point = point->right) && point->x > 0)
	{
		point->down->up = point->up;
		point->up->down = point->down;
		ft_cover(point);
	}
	point->down->up = point->up;
	point->up->down = point->down;
}
