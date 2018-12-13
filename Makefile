# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 12:57:12 by cnotin            #+#    #+#              #
#    Updated: 2018/12/12 19:09:26 by bwan-nan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FIRST = cd libft/ && make re && cd ..

LAST = cd libft/ && make fclean && cd ..

CC = gcc -o

CFLAGS = -Wall -Wextra -Werror

HEADERS = fillit.h

LIBFT = libft/libft.a

SRC = main.c ft_check.c ft_map.c ft_read.c ft_backtrack.c \

all : $(NAME)

$(NAME) :
	$(FIRST) && $(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT)

clean :
	$(LAST)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
