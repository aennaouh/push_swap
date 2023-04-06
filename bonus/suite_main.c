/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:45:52 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/05 00:30:46 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

void	free_stack(t_data *stack)
{
	t_data	*node;

	while (stack != NULL)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

void	suite_main(char **split, int num)
{
	check_duplicat(split);
	check_integer(split);
	check_bigger(split);
	int_unsid(split, num);
}

void	suite_free(t_data *stack_a, t_data *stack_b, char **split)
{
	free_all(split);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	init(t_norm *norm)
{
	norm->stack_a = NULL;
	norm->join = NULL;
	norm->split = NULL;
	norm->i = 0;
	norm->stack_b = NULL;
	norm->join = NULL;
	norm->i = 1;
	norm->num = 1;
}
