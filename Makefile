# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserhii <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 14:39:51 by yserhii           #+#    #+#              #
#    Updated: 2018/11/20 15:50:59 by yserhii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

SRC_DIR =	./src/
OBJ_DIR =	./obj/
INC_DIR =	./inc/
LIB_DIR =	./lib/

SRC =		main.c ft_move.c tetri_valmod.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		cc $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
		cc -c $< -o $@ -I $(INC_DIR)

clean:
		rm -f $(OBJ_FILES)

fclean: clean
		rm -f $(NAME)
re: fclean all

vpath %.c $(SRC_DIR)

all:
	@make -C /libft/ fclean && make -C /libft/
	@clang -Wall -Wextra -Werror -I /libft/includes -o main.o -c main.c
	@clang -o fillit main.o -I /libft/includes -L /libft/ -lft
	@make -C /libft/ fclean

clean:
		@rm -f *.o

fclean: clean
		@rm -f $(NAME)

re: fclean all
