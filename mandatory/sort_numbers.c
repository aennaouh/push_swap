/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:05:04 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/11 05:09:59 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_smallest(t_data **stack)
{
	int		smallest;
	t_data	*tmp;

	if (stack == NULL || (*stack) == NULL)
		return (0);
	tmp = (*stack);
	smallest = (*stack)->index;
	while (tmp != NULL)
	{
		if (smallest > tmp->index)
			smallest = tmp->index;
		tmp = tmp->next;
	}
	return (smallest);
}

void	size_2(t_data **stack_a)
{
	if (stack_a == NULL)
		return ;
	if ((*stack_a) && (*stack_a)->next)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
}

void	suite_size(t_data **stack_a)
{
	t_data	*stack_b;

	stack_b = NULL;
	if (find_index(*stack_a, the_smallest(stack_a)) == 0 && \
	(*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		pb(stack_a, &stack_b);
		sa(stack_a);
		pa(&stack_b, stack_a);
	}
	else if (find_index(*stack_a, the_smallest(stack_a)) == 1)
	{
		if (((*stack_a)->content < (*stack_a)->next->next->content))
			sa(stack_a);
		else
			ra(stack_a);
	}
}

void	size_3(t_data **stack_a)
{
	t_data	*stack_b;

	stack_b = NULL;
	if (!check_sorted(stack_a))
	{
		if (stack_a && (*stack_a) && (*stack_a)->next && (*stack_a)->next->next)
		{
			suite_size(stack_a);
			if (find_index(*stack_a, the_smallest(stack_a)) == 2)
			{
				if ((*stack_a)->content > (*stack_a)->next->content)
				{
					sa(stack_a);
					rra(stack_a);
				}
				else
					rra(stack_a);
			}
		}
	}
}	

void	size_5(t_data **stack_a)
{
	t_data	*stack_b;

	stack_b = NULL;
	if ((*stack_a) == NULL)
		return ;
	while ((lst_size(*stack_a)) > 3)
	{
		if (find_index(*stack_a, the_smallest(stack_a)) < \
		lst_size(*stack_a) / 2)
			while ((*stack_a)->index != the_smallest(stack_a))
				ra(stack_a);
		else
			while ((*stack_a)->index != the_smallest(stack_a))
				rra(stack_a);
		if ((*stack_a) && (*stack_a)->index == the_smallest(stack_a))
		{
			pb(stack_a, &stack_b);
		}
	}
	size_3(stack_a);
	while (stack_b)
	{
		pa(&stack_b, stack_a);
	}
}
