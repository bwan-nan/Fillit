# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 20:05:32 by bwan-nan          #+#    #+#              #
#    Updated: 2019/01/09 20:05:36 by bwan-nan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

HEADERS = fillit.h

SRC = main.c ft_check.c ft_map.c ft_read.c ft_backtrack.c \

all : $(NAME)

$(NAME) :
	@make -C libft
	@clang $(CFLAGS) -c $(SRC)
	@clang $(CLFAGS) *.o -L libft/ -lft -o fillit
	@echo "\033[1;34mFillit\t\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"

clean :
	@make clean -C libft
	@/bin/rm -f *.o
	@echo "\033[1;34mFillit\t\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"


fclean : clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "\033[1;34mFillit\t\t\033[1;33mCleaning executable\t\033[0;32m[OK]\033[0m"

re : fclean all

.PHONY : all clean fclean re
