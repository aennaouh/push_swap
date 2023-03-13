# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:59:49 by aennaouh          #+#    #+#              #
#    Updated: 2023/03/13 00:34:57 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
cc = CC
FLAGS= -Wall -Wextra -Werror -g
HEAD = push_swap.h
SRC = push_swap.c instraction.c push_utilise.c  instraction2.c push_utilise2.c  push_utilise1.c\
linked_list.c sort_numbers.c  instraction3.c test.c sort_number100.c\

OBJ = ${SRC:.c=.o}

all : $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)  
	$(CC) $(FLAGS) $(OBJ) -o push_swap


clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all