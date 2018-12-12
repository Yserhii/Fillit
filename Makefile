# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserhii <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 14:39:51 by yserhii           #+#    #+#              #
#    Updated: 2018/12/10 18:17:40 by yserhii          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the executable file

NAME :=				fillit

# project directories

SRC_DIR :=			./fillit_one/src/
OBJ_DIR :=			./fillit_one/obj/
INC_DIR :=			./fillit_one/inc/

 # project source files

SRC =				main.c lst_fill.c matrix_build.c matrix_node_fill.c\
					matrix_all_var.c matrix_solve.c cover_uncover.c\
					free.c display.c\

# project object files

OBJ =				$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# libraries

LIBFT =				$(LIBFT_DIR)libft.a
LIBFT_DIR :=		libft/
LIBFT_INC :=		$(LIBFT_DIR)includes/
LIBFT_FLAGS :=		-lft -L $(LIBFT_DIR)

# compilation flags

CC_FLAGS :=			-Wall -Wextra -Werror

# add linking flags for different libraries

LINK_FLAGS :=		$(LIBFT_FLAGS)

# header flags

HEADER_FLAGS :=		-I $(INC_DIR)  -I $(LIBFT_INC)

# change compiler for different systems

CC :=				gcc

# rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJ)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(NAME)
		rm -rf $(OBJ_DIR)
		make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
