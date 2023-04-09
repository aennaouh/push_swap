/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:55:28 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/09 10:00:20 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_data *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	int_insid(char **str)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (str[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	index_size(stack_a);
	if (!check_sorted(&stack_a))
	{
		size_check(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

void	size_check(t_data **stack_a, t_data **stack_b)
{
	if (lst_size(*stack_a) == 0)
		return ;
	else if (lst_size(*stack_a) == 2)
	{
		size_2(stack_a);
	}
	else if (lst_size(*stack_a) == 3)
	{
		size_3(stack_a);
	}
	else if (lst_size(*stack_a) >= 3 && lst_size(*stack_a) <= 5)
	{
		size_5(stack_a);
	}
	else if (lst_size(*stack_a) <= 100)
	{
		size_100(stack_a, stack_b);
	}
	else if (lst_size(*stack_a) <= 500)
	{
		size_500(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_norm	norm;

	init(&norm);
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		norm.i = 1;
		norm.join = ft_strdup3("");
		while (argv[norm.i])
		{
			norm.join = ft_strjoi(norm.join, " ");
			norm.join = ft_strjoi(norm.join, argv[norm.i]);
			norm.i++;
		}
		norm.split = ft_split(norm.join, ' ');
		free(norm.join);
	}
	check_empty_spaces(argv);
	suite_main(norm.split);
	free_all(norm.split);
}
