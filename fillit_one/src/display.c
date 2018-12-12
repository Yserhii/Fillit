/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:21:58 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:19:16 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstrn(char *str, int sidelen)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
		if (i % sidelen == (sidelen - 1))
			write(1, "\n", 1);
	}
	free(str);
}

void	ft_display(t_stack **res, int sidelen, int count)
{
	int			count1;
	char		*str;
	t_matrix	*col;
	t_matrix	*node;
	t_stack		*point;

	if (!(str = ft_strnew(sidelen * sidelen)))
		return ;
	ft_memset(str, '.', (sidelen * sidelen));
	point = *res;
	count1 = count;
	while (point && count1--)
	{
		node = point->content;
		col = node->column;
		while ((node = node->right) && node->x > 0)
			str[node->x - 1] = ('A' - 1) + col->x + count;
		point = point->next;
	}
	ft_putstrn(str, sidelen);
}
