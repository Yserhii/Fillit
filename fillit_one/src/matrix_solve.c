/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:20:46 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 19:17:19 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_matrix_solve(t_matrix *head, t_stack **res, int i)
{
	t_matrix		*var;
	t_matrix		*col;

	col = head->right;
	var = col->down;
	if ((col->x > 0 || head->right == head))
		return (1);
	while (var != col)
	{
		choose_and_cover(var, res);
		if (ft_matrix_solve(head, res, i))
			return (1);
		else
		{
			if (i > 100)
				return (0);
			i++;
			check_and_uncover(res);
			var = var->down;
		}
	}
	return (0);
}
