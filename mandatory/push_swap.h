/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:53:09 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/09 10:00:57 by aennaouh         ###   ########.fr       */
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

typedef struct s_norm
{
	int				i;
	char			**split;
	char			*join;
	int				num;
	t_data			*stack_a;
	t_data			*stack_b;
	int				top;
	int				end;
	int				chunk_p;
	char			*tab;
}					t_norm;

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
char	*ft_strjoi(const char *s1, const char *s2);
char	*ft_strjoi2(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	int_insid(char **str);
void	ft_putnber(int n);
void	ft_lstadd_front(t_data **lst, t_data *new);
int		lst_size(t_data *stack);

void	size_2(t_data **stack_a);
void	size_3(t_data **stack_a);
int		the_smallest(t_data **stack);
void	index_size(t_data *stack_a);
void	size_5(t_data **stack_a);

void	ft_putnber(int n);
void	ft_putstr(char *str);
char	*ft_strdup3(const char *s1);

void	rrb(t_data **stack_b);
void	size_100(t_data **stack_a, t_data **stack_b);
void	size_500(t_data **stack_a, t_data **stack_b);
int		max_index(t_data **stack_b);
int		pos_max_5(t_data **stack_b);
void	largest_number_5(t_data **stack_b);
void	chunk_check_5(t_data **stack_a, t_data **stack_b, int end, int top);

int		max_index_5(t_data **stack_b);
void	size_check(t_data **stack_a, t_data **stack_b);
void	largest_number(t_data **stack_a, t_data **stack_b);

int		pos_max_5(t_data **stack_b);
void	free_stack(t_data *stack);
void	free_all(char **split);
void	suite_main(char **split);
void	suite_free(t_data *stack_a, t_data *stack_b, char **split);
void	init(t_norm *norm);
int		check_sorted(t_data **stack_a);
void	ft_lstclear(t_data **lst);

void	check_empty_spaces(char **str);
int		is_empty(char *str);
#endif