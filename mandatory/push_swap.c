/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:55:28 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 11:01:46 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_insid(char **str, int num)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < num - 1)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	i = 0;
	index_size(stack_a);
	//printf("%p\t%p\n", stack_a, stack_b);
	size_check(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	//ft_lstclear(&stack_a);
	//t_lstclear(&stack_b);
	//while (str[i])
	//free(str[i]);
	//free(str);
}

void	size_check(t_data **stack_a, t_data **stack_b)
{
	if (lst_size(*stack_a) == 0)
		return ;
	else if (lst_size(*stack_a) == 3)
	{
		size_3(stack_a);
	}
	else if (lst_size(*stack_a) >= 0 && lst_size(*stack_a) <= 5)
	{
		size_5(stack_a);
	}
	else if (lst_size(*stack_a) <= 100)
	{
		size_100(stack_a, stack_b);
	}
	else if (lst_size(*stack_a) <= 500)
	{
		size_100(stack_a, stack_b);
	}
}

void	func(void)
{
	system("leaks push_swap");
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
			norm.num ++;
		}
		norm.split = ft_split(norm.join, ' ');
		free(norm.join);
	}
	suite_main(norm.split, norm.num);
	free_all(norm.split);
	//printf("%p\t%p\n", norm.stack_a, norm.stack_b);
	//atexit(func);
	// while(1);
}
