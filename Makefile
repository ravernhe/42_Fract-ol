# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 12:07:55 by ravernhe          #+#    #+#              #
#    Updated: 2019/07/06 15:30:54 by ravernhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	fractol

SRC 		=	./srcs/main.c\
		  		./srcs/mandelbrot.c\
		  		./srcs/julia.c\
				./srcs/leaf.c\
				./srcs/bonus.c\
				./srcs/init.c\
				./srcs/mlx_func.c

FLAGS 		=	-Werror -Wall -Wextra

FRAMEWORK	=	-framework OpenGL -framework AppKit

CC 			=	gcc

INC			=	./srcs/frac.h

OBJ 		=	$(SRC:.c=.o) $(INC)

all: $(NAME)

%.o: %.c
			@$(CC) -c $< -o $@ $(FLAGS)

$(NAME): $(OBJ)
			@make -C ./libft
			@$(CC) $(FLAGS) -I /usr/local/include $(SRC) -o $(NAME)\
			-I libft/ -L libft/ -lft -L /usr/local/lib/ -lmlx $(FRAMEWORK)

clean:
			@make -C libft/ clean
			@rm -rf $(OBJ)

fclean: clean
			@make -C libft/ fclean
			@rm -rf $(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
