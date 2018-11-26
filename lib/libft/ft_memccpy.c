/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:47:12 by yserhii           #+#    #+#             */
/*   Updated: 2018/11/01 13:33:09 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char*)src)[i] == ((unsigned char)c))
		{
			i++;
			ft_memcpy(dst, src, i);
			return (&dst[i]);
		}
		i++;
	}
	ft_memcpy(dst, src, i);
	return (NULL);
}
