# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:59:49 by aennaouh          #+#    #+#              #
#    Updated: 2023/04/01 02:05:54 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B-NAME = checker
cc = CC
FLAGS= -Wall -Wextra -Werror -g -fsanitize=address -static-libsan
HEAD = push_swap.h
HEAD_BONUS = ../bonus/push_swap.h
SRC =  instraction.c push_utilise.c  instraction2.c push_utilise2.c  push_utilise1.c suite_sort_num_500.c\
linked_list.c sort_numbers.c  instraction3.c test.c sort_number100.c sort_numbers500.c condition_of_error.c push_swap.c \

SRC1 = ../bonus/instraction.c ../bonus/instraction2.c  ../bonus/instraction3.c ../bonus/push_utilise.c  ../bonus/condition_of_error.c ../bonus/linked_list.c \
../bonus/check.c ../bonus/push_utilise2.c ../bonus/ push_utilise1.c s ../bonus/get_next_line/get_next_line.c ../bonus/get_next_line/get_next_line_utils.c \


OBJ = ${SRC:.c=.o}

OBJ1 = ${SRC1:.c=.o}

all : $(NAME)

%.o: %.c $(HEAD) $(HEAD_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o push_swap

bonus : $(HEAD_BONUS) $(OBJ1)
	$(CC) $(FLAGS) $(OBJ1) -o checker

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
#-fsanitize=address -static-libsan