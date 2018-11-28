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

typedef struct			s_matrix
{
	char				tetrim;
	struct s_matrix		*top;
	struct s_matrix		*bottom;
	struct s_matrix		*left;
	struct s_matrix		*right;
	struct s_matrix		*abc;
	int					x;
	int					y;
}						t_matrix;

int						ft_validate(char *buf);
void					ft_lstfill(t_list **lst, char *buf);
char					*ft_move(char *buf);
void					ft_attempt(char *buf, char **content, int num);

#endif
