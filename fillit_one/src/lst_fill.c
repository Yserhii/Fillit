/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:17:49 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/10 18:19:22 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_validate(char *buf)
{
	int			near;
	int			dot;
	int			i;

	near = 0;
	dot = 0;
	i = 0;
	if ((buf[4] == '\n' && buf[9] == '\n' && buf[14] == '\n'
	&& buf[19] == '\n') && (buf[20] == '\n' || buf[20] == '\0'))
		while (buf[i] && (buf[i] == '#' || buf[i] == '.' || buf[i] == '\n'))
		{
			if (buf[i] == buf[i - 1] && buf[i] == '#')
				near++;
			if (buf[i] == buf[i + 1] && buf[i] == '#')
				near++;
			if (buf[i] == buf[i + 5] && buf[i] == '#')
				near++;
			if (buf[i] == buf[i - 5] && buf[i] == '#')
				near++;
			if (buf[i] == '.')
				dot++;
			i++;
		}
	return (((near == 6 || near == 8) && dot == 12) ? 1 : 0);
}

static void		ft_attempt(char *buf, char **content, int num)
{
	int			i;
	int			chr;
	char		*point;

	i = 0;
	chr = ft_strchr(buf, '#') - (char*)buf;
	point = *content;
	while (buf[i])
	{
		if (buf[i] == '#')
			point[(i - chr) + num] = buf[i];
		i++;
	}
}

static char		*ft_move(char *buf)
{
	char		*content;
	int			num;
	int			i;

	num = 0;
	content = ft_strnew(20 + 1);
	while (ft_validate(content) != 1)
	{
		i = 0;
		while (i < 20)
		{
			if ((i % 5) == 4)
				content[i] = '\n';
			else
				content[i] = '.';
			i++;
		}
		ft_attempt(buf, &content, num);
		num++;
	}
	return (content);
}

void			ft_lstfill(t_list **lst, char *buf)
{
	char		*tmp;
	t_list		*point;

	tmp = ft_move(buf);
	point = *lst;
	point = ft_lstnew(tmp, 21);
	if (*lst == NULL)
		ft_lstadd(lst, point);
	else
		ft_lstadd_end(lst, point);
	free(tmp);
}
