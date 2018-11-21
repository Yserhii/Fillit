/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 13:47:24 by yserhii           #+#    #+#             */
/*   Updated: 2018/11/04 12:48:58 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	tmp = (char*)malloc(sizeof(char) * (i + 1));
	if (tmp == 0)
		return (NULL);
	ft_strcpy(tmp, s1);
	ft_strcpy(&tmp[ft_strlen(s1)], s2);
	return (tmp);
}
