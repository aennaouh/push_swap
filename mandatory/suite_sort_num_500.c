/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_sort_num_500.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:17:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 02:13:52 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index_5(t_data **stack_b)
{	
	int		max;
	t_data	*tmp;

	max = 0;
	tmp = (*stack_b);
	while (tmp)
	{
		if (tmp->index >= max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	pos_max_5(t_data **stack_b)
{
	t_data	*tmp;
	int		pos;
	int		index;

	pos = 0;
	index = max_index_5(stack_b);
	tmp = (*stack_b);
	while (tmp != NULL)
	{
		if (tmp->index == max_index_5(stack_b))
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

void	suit_largest_number_5(t_data **stack_b)
{
	while ((*stack_b)->index != max_index(stack_b))
	{
		rb(stack_b);
	}
}

void	largest_number_5(t_data **stack_b)
{
	t_data	**stack_a;
	int		pos;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < lst_size(*stack_b))
	{
			pos = pos_max_5(stack_b);
		if (pos > lst_size(*stack_b) / 2)
		{
			while ((*stack_b)->index != max_index(stack_b))
			{
				rrb(stack_b);
			}
		}
		else
			suit_largest_number_5(stack_b);
		if ((*stack_b)->index == max_index(stack_b))
		{
			pa(stack_b, stack_a);
		}
				i++;
	}
}
