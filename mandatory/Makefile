# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:59:49 by aennaouh          #+#    #+#              #
#    Updated: 2023/03/31 00:29:14 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
cc = CC
FLAGS= -Wall -Wextra -Werror -g -fsanitize=address -static-libsan
HEAD = push_swap.h
HEAD_BONUS = push_swap_bonus.h
SRC =  instraction.c push_utilise.c  instraction2.c push_utilise2.c  push_utilise1.c suite_sort_num_500.c\
linked_list.c sort_numbers.c  instraction3.c test.c sort_number100.c sort_numbers500.c condition_of_error.c push_swap.c\

SRC1=  ..bonus/check.c ../bonus/get_next_line/get_next_line.c ../bonus/get_next_line/get_next_line_utils.c \


OBJ = ${SRC:.c=.o}

OBJ1 = ${SRC1:.c=.o}

all : $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)  
	$(CC) $(FLAGS) $(OBJ) -o push_swap

bonus : $(HEAD_BONUS)
	$(CC) $(FLAGS) $(OBJ1) -o push_swap

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

#-fsanitize=address -static-libsan