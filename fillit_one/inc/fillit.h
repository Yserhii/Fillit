/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrudyka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:58:44 by vrudyka           #+#    #+#             */
/*   Updated: 2018/12/03 13:35:36 by vrudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef struct			s_matrix
{
	struct s_matrix		*up;
	struct s_matrix		*down;
	struct s_matrix		*left;
	struct s_matrix		*right;
	struct s_matrix		*column;
	int					x;
	int					y;
}						t_matrix;

typedef struct			s_stack
{
	t_matrix			*content;
	struct s_stack		*next;
}						t_stack;

void					ft_lstfill(t_list **lst, char *buf);
int						ft_validate(char *buf);

t_matrix				*ft_matrix_fill(t_list **lst, int count, int sidelen);
void					ft_create_node_all_var(int *tab, t_matrix *pmatrix,
							int letter);
void					ft_node_var(t_matrix *pmatrix, t_matrix *head, int y);
t_matrix				*ft_node_elem(t_matrix *pmatrix, t_matrix *head,
							t_matrix *col, t_matrix *back);
t_matrix				*ft_node_fill(t_matrix *left, t_matrix *right,
							int x, int y);
void					ft_all_var_tab(t_list *lst, int sidelen,
							t_matrix *pmatrix, int count);
int						*ft_create_tab(t_list *lst, int sidelen);
void					ft_new_var(int *tab, int sidelen, t_list *lst);

int						ft_matrix_solve(t_matrix *head, t_stack **res, int i);
void					choose_and_cover(t_matrix *pmatrix, t_stack **res);
void					ft_cover(t_matrix *curr);
void					ft_stackadd(t_matrix *var, t_stack **res);
void					check_and_uncover(t_stack **res);
void					ft_uncover(t_matrix *curr);

void					ft_lstfree(t_list **lst);
void					ft_matrixfree(t_matrix *head);

void					ft_display(t_stack **res, int sidelen, int count);
void					ft_putstrn(char *str, int sidelen);

#endif
