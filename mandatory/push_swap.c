/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:55:28 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/01 02:57:51 by aennaouh         ###   ########.fr       */
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
	while (i < num)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[i])));
			i++;
	}
	index_size(stack_a);
	//print_stack(stack_a);
	//size_check(&stack_a, &stack_b);
	//size_500(&stack_a, &stack_b);
	//print_stack(stack_a);
	//print_stack(stack_b);
	//print_stack(stack_a);
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
	else if (lst_size(*stack_a) >= 6 && lst_size(*stack_a) <= 100)
	{
		size_100(stack_a, stack_b);
	}
	else if (lst_size(*stack_a) >= 100 && lst_size(*stack_a) <= 500)
	{
		size_500(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	char	*join = NULL;
	t_data	*stack_a;
	t_data	*stack_b;
	int		num;

	stack_a = NULL;
	join = NULL;
	stack_b = NULL;
	num = 0;
	split = NULL;
	i = 1;
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		i = 1;
		join = ft_strd(" "); // lllllllllllllllllllllllllllllllllllllllllllll
		while (argv[i])
		{
			join = ft_strjoi(join, " ");
			join = ft_strjoi(join, argv[i]);
			i++;
			num++;
		}
		split = ft_split(join, ' ');
	}
	check_duplicat(split);
	check_integer(split);
	check_bigger(split);
	int_insid(split, num);
	index_size(stack_a);
	size_check(&stack_a, &stack_b);
}
