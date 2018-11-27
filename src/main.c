/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:35:18 by yserhii           #+#    #+#             */
/*   Updated: 2018/11/23 12:20:54 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstfill(t_list **lst, char *buf)
{
	char		*content;
	t_list		*point;
	int			i;

	point = *lst;
	i = 0;
	content = ft_move(buf);
	point = ft_lstnew(content, 21);
	if (*lst == NULL)
		ft_lstadd(lst, point);
	else
		ft_lstadd_end(lst, point);
}

int		main(int argc, char **argv)
{
	t_list		*lst;
	char		*buf;
	int			count;
	int			fd;

	count = 0;
	if (argc == 2)
	{
		buf = (char*)ft_memalloc(21 + 1);
		fd = open(argv[1], O_RDONLY);
		while (read(fd, buf, 21) > 0 && fd > 0)
		{
			if (count < 26 && (ft_validate(buf)))
				ft_lstfill(&lst, buf);
			else
				break ;
			count++;
		}
		/*call function for MATRIX BUILD*/
		/*call function for MATRIX SOLVE*/
	}
	/*free & error if needed*/
	return (1);
}

/*

a) function to move to the left top corner

b) function to take tetri from LIST_1
put into MATRIX

c) function to work the dancing links
*/
