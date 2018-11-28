/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_matrix_build.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:57:32 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/28 12:57:34 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstfill(t_list **lst, char *buf)
{
	char	*content;
	t_list	*point;
	int		i;

	point = *lst;
	i = 0;
	content = ft_move(buf);
	point = ft_lstnew(content, 21);
	if (*lst == NULL)
		ft_lstadd(lst, point);
	else
		ft_lstadd_end(lst, point);
}

void		ft_create_head(t_matrix **matrix)
{
	/*create head*/
}

void		ft_matrix_fill(t_matrix **matrix, t_list *lst, int count)
{
	t_matrix		*point;

	point = *matrix;
	ft_create_head(matrix);
	while (lst->next)
	{
		/*while *content create t_matrix*/
		/*lst = lst->next*/
	}
}
