# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ravernhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/06 14:55:06 by ravernhe          #+#    #+#              #
#    Updated: 2019/07/06 14:55:08 by ravernhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCR		= ft_atoi.c\
		  ft_atoi_base.c\
		  ft_atoi_i.c\
		  ft_atoi_base_i.c\
		  ft_split_whitespaces.c\
		  ft_strjoin_free_s1s2.c\
		  ft_strjoin_free_s1.c\
		  ft_itoa.c\
		  ft_sqrt.c\
		  ft_memalloc.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_memdel.c\
		  ft_strlcat.c\
		  ft_memset.c\
		  ft_memccpy.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_lstnew.c\
		  ft_lstdelone.c\
		  ft_lstdel.c\
		  ft_lstadd.c\
		  ft_lstiter.c\
		  ft_lstmap.c\
		  ft_bzero.c\
		  ft_isdigit.c\
		  ft_putendl.c\
		  ft_putstr.c\
		  ft_strchr.c\
		  ft_strdel.c\
		  ft_striteri.c\
		  ft_strmapi.c\
		  ft_strnequ.c\
		  ft_strstr.c\
		  ft_toupper.c\
		  ft_isalnum.c\
		  ft_isprint.c\
		  ft_putendl_fd.c\
		  ft_putstr_fd.c\
		  ft_strclr.c\
		  ft_strdup.c\
		  ft_strjoin.c\
		  ft_strncat.c\
		  ft_strnew.c\
		  ft_strsub.c\
		  ft_isalpha.c\
		  ft_putchar.c\
		  ft_putnbr.c\
		  ft_strsplit.c\
		  ft_strcmp.c\
		  ft_strequ.c\
		  ft_strlen.c\
		  ft_strncmp.c\
		  ft_strnstr.c\
		  ft_strtrim.c\
		  ft_isascii.c\
		  ft_putchar_fd.c\
		  ft_putnbr_fd.c\
		  ft_strcat.c\
		  ft_strcpy.c\
		  ft_striter.c\
		  ft_strmap.c\
		  ft_strncpy.c\
		  ft_strrchr.c\
		  ft_tolower.c\
		  ft_getnbr.c\
		  get_next_line.c

OBJS	= $(SCR:.c=.o)

FLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

CC		= gcc -c $(FLAGS) $(SCR)

all : $(NAME)

$(NAME):
	@$(CC)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
