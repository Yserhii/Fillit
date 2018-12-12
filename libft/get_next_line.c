/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:07:00 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/19 14:31:40 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_line_fill(char **lst, char **line, int chr)
{
	char			*point;

	if (ft_strchr(*lst, '\n') == NULL)
		chr = ft_strlen(*lst);
	*line = ft_strnew(chr);
	*line = ft_strncpy(*line, *lst, chr);
	point = *lst;
	*lst = ft_strsub(point, (chr + 1), (ft_strlen(point) - (chr)));
	free(point);
	return (1);
}

char	*ft_strjoin_free(char *lst, char *buf)
{
	char			*point;

	point = lst;
	lst = ft_strjoin(lst, buf);
	free(point);
	return (lst);
}

t_list	*ft_lstcheck(int fd, t_list **point)
{
	t_list			*tmp;

	tmp = *point;
	while (tmp != NULL)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	tmp->content_size = fd;
	ft_lstadd(point, tmp);
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	char			*buf;
	t_list			*point;
	int				chr;
	int				rv;

	if (BUFF_SIZE < 1 || fd < 0)
		return (-1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	point = ft_lstcheck(fd, &lst);
	while ((rv = read(fd, buf, BUFF_SIZE)) > 0)
	{
		point->content = ft_strjoin_free(point->content, buf);
		ft_bzero(buf, BUFF_SIZE);
		if (ft_strchr((char*)point->content, '\n') != NULL)
			break ;
	}
	if (rv < 0)
		return (-1);
	chr = ft_strchr((char*)point->content, '\n') - (char*)point->content;
	free(buf);
	if (*(char*)point->content != '\0')
		return (ft_line_fill((char**)&point->content, line, chr));
	return (0);
}
