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

char	*color(char c)
{
	int			n;

	n = (c - 'A') % 7;
	switch (n)
	{
		case 1:
			return (KNRM);
		case 2:
			return (KRED);
		case 3:
			return (KGRN);
		case 4:
			return (KYEL);
		case 5:
			return (KBLU);
		case 6:
			return (KMAG);
		case 7:
			return (KCYN);
	}
	return (KCYN);
}

void	ft_putstrn(char *str, int sidelen)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			printf("%s%c", KWHT, str[i]);
		else
			printf("%s%c", color(str[i]), str[i]);
		if (i % sidelen == (sidelen - 1))
			printf("%s\n", KWHT);
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
