/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:22:26 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:18:43 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			error(void)
{
	write(1, "error\n", 6);
	return (0);
}

static int			ft_lst(int fd, t_list **lst)
{
	int				count;
	int				sum;
	int				rt;
	char			*buf;

	count = 0;
	sum = 0;
	buf = (char*)ft_memalloc(21 + 1);
	while ((rt = read(fd, buf, 21)) > 0 && fd > 0)
	{
		sum += rt;
		if (count < 26 && (ft_validate(buf)))
			ft_lstfill(lst, buf);
		else
			return (0);
		count++;
		ft_bzero(buf, 21 + 1);
	}
	if (((sum + 1) % 21) != 0 || fd < 0)
		return (0);
	free(buf);
	return (count);
}

static t_stack		*ft_matrix(int count, t_list *lst, int i)
{
	int				rt;
	int				sidelen;
	t_matrix		*matrix;
	t_stack			*res;
	t_list			*point;

	sidelen = 2;
	while ((sidelen * sidelen) < (count * 4))
		sidelen++;
	rt = 0;
	while (rt <= 0)
	{
		point = lst;
		matrix = ft_matrix_fill(&point, count, sidelen);
		rt = ft_matrix_solve(matrix, &res, i);
		ft_matrixfree(matrix);
		sidelen++;
	}
	sidelen--;
	ft_display(&res, sidelen, count);
	return (res);
}

int					main(int ac, char **av)
{
	int				i;
	int				count;
	t_list			*lst;
	t_stack			*res;

	i = 0;
	if (ac != 2)
		return (error());
	count = ft_lst((open(av[1], O_RDONLY)), &lst);
	if (count != 0)
		res = ft_matrix(count, lst, i);
	else
		return (error());
	return (0);
}
