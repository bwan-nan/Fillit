# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 12:28:58 by cnotin            #+#    #+#              #
#    Updated: 2018/12/14 11:23:24 by bwan-nan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

OPTION = -I $(HEADER)


SRC = ft_strcpy.c ft_strlen.c ft_strdup.c ft_strncpy.c ft_strcmp.c \
		ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_islower.c \
		ft_toupper.c ft_isupper.c ft_tolower.c ft_strstr.c ft_strnstr.c \
		ft_bzero.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_isascii.c \
		ft_isprint.c ft_strchr.c ft_strrchr.c ft_memset.c ft_memcpy.c \
		ft_memccpy.c ft_memmove.c ft_atoi.c ft_memchr.c ft_memcmp.c \
		ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_strnew.c \
		ft_memdel.c ft_memalloc.c ft_strdel.c ft_strclr.c ft_striter.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_striteri.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_itoa.c ft_strsplit.c \
		ft_lstnew.c ft_lstadd.c ft_lstiter.c ft_lstdelone.c ft_lstdel.c \
		ft_lstmap.c ft_lstcount.c ft_printlst.c ft_nb_word.c ft_strrev.c \
		ft_isspace.c ft_strndup.c ft_strjoinf.c get_next_line.c ft_realloc.c \
		ft_sqrt.c ft_find_next_sqrt.c ft_recursive_power.c ft_strjoinendl.c \
		ft_strdupendl.c


OBJ = $(SRC:.c=.o)

$(NAME):
		$(CC) -c $(FLAGS) $(SRC) $(OPTION)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)


all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf  $(NAME)

re: fclean all
