/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:58:44 by vrudyka           #+#    #+#             */
/*   Updated: 2018/11/26 13:58:45 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <stdio.h>

typedef struct	matrix
{
	char			*tetrim;
	struct matrix	*top;
	struct matrix	*bottom;
	struct matrix	*left;
	struct matrix	*right;
	struct matrix	*column;
	int				x;
	int				y;
}					d_list;

int		ft_validate(char *buf);
void	ft_attmpt(char *buf, char **content, int num);
char	*ft_move(char *buf);

#endif
