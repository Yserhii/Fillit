/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_valmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:28:15 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/26 12:28:17 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validate(char *buf)
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

void	ft_attmpt(char *buf, char **content, int num)
{
	int		i;
	int		chr;
	char	*point;

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

char	*ft_move(char *buf)
{
	char	*content;
	int		num;
	int		i;

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
		ft_attmpt(buf, &content, num);
		num++;
	}
	printf("%s\n", content);
	return (content);
}
