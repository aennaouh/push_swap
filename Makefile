# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 18:59:49 by aennaouh          #+#    #+#              #
#    Updated: 2023/04/01 03:09:02 by aennaouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B-NAME = checker
cc = CC
FLAGS= -Wall -Wextra -Werror -g -fsanitize=address -static-libsan
HEAD = push_swap.h
HEAD_BONUS = bonus/push_swap_bonus.h
SRC =  mandatory/instraction.c  mandatory/push_utilise.c  mandatory/instraction2.c  mandatory/push_utilise2.c   mandatory/push_utilise1.c  mandatory/suite_sort_num_500.c\
 mandatory/linked_list.c  mandatory/sort_numbers.c   mandatory/instraction3.c  mandatory/test.c  mandatory/sort_number100.c  mandatory/sort_numbers500.c  mandatory/condition_of_error.c  mandatory/push_swap.c \

SRC1 = bonus/instraction.c bonus/instraction2.c  bonus/instraction3.c bonus/push_utilise.c bonus/condition_of_error.c bonus/linked_list.c\
bonus/check.c bonus/push_utilise2.c bonus/push_utilise1.c  bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \


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

re_bonus: fclean bonus
#-fsanitize=address -static-libsan