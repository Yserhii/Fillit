/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:35:18 by yserhii           #+#    #+#             */
/*   Updated: 2018/11/20 15:36:35 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_validate(char *buf)
{
	int			i;
	int			hash;
	int			dot;

	i = 0;
	hash = 0;
	dot = 0;
	if ((buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n'
	&& buf[19] == '\n') && (buf[20] == '\n' || buf[20] == '\0'))
		while (buf[i])
		{
			if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
				return (0);
			if ((buf[i] == '#') && (buf[i] == buf[i + 1] ||
			buf[i] == buf[i - 1] || buf[i] == buf[i + 5] ||
			buf[i] == buf[i - 5]))
				hash++;
			if (buf[i] == '.')
				dot++;
			i++;
		}
	if (hash == 4 && dot == 12)
		return (1);
	return (0);
}

void	ft_lstfill(t_list **lst, char *buf, char letter)
{
	t_list		*point;
	char		**content;
	int			i;

	point = *lst;
	i = -1;
	while (*buf)
	{
		if (*buf == '#')
			*buf = letter;
	}
	content = ft_strsplit(buf, '\n');
	while (point != NULL)
		point = point->next;
	point = ft_lstnew(content, 21);
	printf("%s\n", (char*)point->content);
	ft_lstadd(lst, point);
}

/*char	*ft_finalout(t_list **lst, int count)
{
	char		*square;
	//int		countold;
	t_list		*point;
	int 		i;
	int			a;

	point =  *lst;
	i = 0;
	a = 0;
	//countold = count;
	//if (countold < 0)
	//	return ;
	if (!(square = (char*)ft_memalloc(4 * count)))
		return (NULL);
	ft_memset(square, '.', 4 * count);
	while (point)
	{
		while (((char*)point->content)[a] == '.')
			a++;
		if (square[i] == '.')
		{
			square[i] = ((char*)point->content)[a]
			a++;
		}
		i++;
	}
}*/

int		main(int argc, char **argv)
{
	t_list		*lst;
	char		letter;
	char		*buf;
	int			count;
	int			fd;

	count = 0;
	letter = 'A';
	if (argc == 2)
	{
		buf = ft_memalloc(21 + 1);
		fd = open(argv[1], O_RDONLY);
		while (read(fd, buf, 21) > 0 && fd > 0)
		{
			if (count < 26 && (ft_validate(buf)))
				ft_lstfill(&lst, buf, letter);
			else
				break ;
			count++;
			letter++;
		}
	}
	/*free & error if needed*/
	return (1);
}
