/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_all_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:24:39 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:19:32 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_new_var(int *tab, int sidelen, t_list *lst)
{
	int		i;
	int		k;
	int		coeff;

	i = -1;
	k = -1;
	coeff = 1;
	while (((char *)lst->content)[++k])
		if (coeff < (k % 5 + 1) && ((char *)lst->content)[k] == '#')
			coeff = (k % 5 + 1);
	if (tab[1] % sidelen == 0 || tab[2] % sidelen == 0 || tab[3] % sidelen == 0)
		while (tab[++i])
			tab[i] = tab[i] + coeff;
	else
		while (tab[++i])
			tab[i] = tab[i] + 1;
}

int		*ft_create_tab(t_list *lst, int sidelen)
{
	int		i;
	int		k;
	int		coor;
	int		coeff;
	int		*tab;

	i = -1;
	k = 0;
	coor = 1;
	coeff = sidelen - 4;
	tab = (int *)ft_memalloc(4);
	while (i < 3)
	{
		if (((char *)lst->content)[k] == '#')
			tab[++i] = coor;
		if (((char *)lst->content)[k] != '\n')
			coor++;
		if (k == 4 || k == 8 || k == 12)
			coor += coeff;
		k++;
	}
	return (tab);
}

void	ft_all_var_tab(t_list *lst, int sidelen, t_matrix *pmatrix, int letter)
{
	int			*tab;

	tab = ft_create_tab(lst, sidelen);
	while (tab[3] <= sidelen * sidelen)
	{
		ft_create_node_all_var(tab, pmatrix, letter);
		ft_new_var(tab, sidelen, lst);
	}
	free(tab);
}
