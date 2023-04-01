/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:53:09 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/01 02:23:11 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_data
{
	int				content;
	int				index;
	struct s_data	*next;
}t_data;

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
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	ft_putnber(int n);
void	ft_lstadd_front(t_data **lst, t_data *new);
int		lst_size(t_data *stack);

void	size_2(t_data **stack_a);
void	print_stack(t_data *stack);
void	size_3(t_data **stack_a);
int		the_smallest(t_data **stack);
void	index_size(t_data *stack_a);
void	size_5(t_data **stack_a);

void	ft_putnber(int n);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);

int		secand_index_5(t_data **stack_b);
void	rrb(t_data **stack_b);
void	size_100(t_data **stack_a, t_data **stack_b);
void	size_500(t_data **stack_a, t_data **stack_b);
int		max_index(t_data **stack_b);
int		pos_max_5(t_data **stack_b);
void	largest_number_5(t_data **stack_b);
int		get_instr_5(t_data *stack_b, int index);
void	chunk_check_5(t_data **stack_a, t_data **stack_b, int end, int top);

t_data	*int_unsid(char **str, int num);
void	read_instructions(t_data **stack_a, t_data **stack_b);
void	check_if_sorted(t_data *stack_a);
int		pos_secand_5(t_data **stack_b);
int		max_index_5(t_data **stack_b);

#endif