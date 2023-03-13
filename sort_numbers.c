/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:05:04 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/12 10:56:53 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	the_smallest(t_data **stack)
{
	int		smallest;
	t_data	*tmp;

	smallest = (*stack)->index;
	tmp = (*stack);
	while (tmp != NULL)
	{
		if (smallest > tmp->index)
			smallest = tmp->index;
		tmp = tmp->next;
	}

	return (smallest);
}

void	index_size(t_data *stack_a)
{
	t_data	*tmpi;
	t_data	*tmpj;
	int		index;

	tmpi = stack_a;
	if (stack_a == NULL)
		return ;
	while (tmpi != NULL)
	{
	tmpj = stack_a;

		index = 0;
		while (tmpj != NULL)
		{
			if (tmpj->content != tmpi->content && tmpi->content > tmpj->content)
				index++;
			tmpj = tmpj->next;
		}
		tmpi->index = index;
		tmpi = tmpi->next;
	}
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

void	size_3(t_data **stack_a)
{
	if (stack_a == NULL)
		return ;
	if ((*stack_a) && (*stack_a)->next && (*stack_a)->next->next)
	{
		if ((*stack_a) > (*stack_a)->next && (*stack_a)->next->next)
		{
			ra(stack_a);
		}
		else if ((*stack_a)->next > (*stack_a) && (*stack_a)->next->next)
		{
			rra(stack_a);
		}
		if (1 > 2)
		{
			sa(stack_a);
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
		while ((*stack_a)->index != the_smallest(stack_a))
		{
			rra(stack_a);
		}
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
