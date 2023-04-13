/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:09:40 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/10 21:17:59 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include<stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "../mandatory/push_swap.h" 
# include "get_next_line/get_next_line.h"

void	read_instructions(t_data **stack_a, t_data **stack_b);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

char	**ft_split(char const *s, char c);
void	check_integer(char **str);
void	check_bigger(char **str);
void	check_duplicat(char **str);
void	ra(t_data **stack_a);
void	rrr(t_data **stack_b, t_data **stack_a);
void	rra(t_data **stack_a);
void	rr(t_data **stack_a, t_data **stack_b);
void	rb(t_data **stack_b);
void	ra(t_data **stack_a);
void	pa(t_data **stack_b, t_data **stack_a);
void	pb(t_data **stack_a, t_data **stack_b);
void	ss(t_data **stack_b, t_data **stack_a);
void	sb(t_data **stack_b);
void	sa(t_data **stack_a);
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
t_data	*ft_lstnew(int content);
void	ft_lstadd_back(t_data **lst, t_data *new);
char	*ft_strjoin2(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	ft_putnber(int n);
t_data	*ft_lstnew(int content);
int		lst_size(t_data *stack);

void	size_2(t_data **stack_a);
void	size_3(t_data **stack_a);
int		the_smallest(t_data **stack);
void	index_size(t_data *stack_a);
void	size_5(t_data **stack_a);

void	ft_putnber(int n);
void	ft_putstr(char *str);
char	*ft_strdpp(const char *s1);

void	rrb(t_data **stack_b);

void	int_unsid(char **str);
void	index_size(t_data *stack_a);
int		lst_size(t_data *stack);
void	free_all(char **split);
void	free_stack(t_data *stack);
void	suite_free(t_data *stack_a, t_data *stack_b, char **split);
void	init(t_norm *norm);
void	suite_main(char **split);
int		check_sorted(t_data **stack_a);
void	check_empty_spaces(char **str);
int		ft_strlen_lien(char **s);

#endif