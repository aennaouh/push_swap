/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:58:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/30 00:05:07 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_data **stack_b)
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

int	pos_max(t_data **stack_b)
{
	t_data	*tmp;
	int		pos;
	int		index;

	pos = 0;
	index = max_index(stack_b);
	tmp = (*stack_b);
	while (tmp != NULL)
	{
		if (tmp->index == max_index(stack_b))
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

void	largest_number(t_data **stack_b)
{
	t_data	**stack_a;
	int		pos;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < lst_size(*stack_b))
	{
			pos = pos_max(stack_b);
		if (pos > lst_size(*stack_b) / 2)
		{
			while ((*stack_b)->index != max_index(stack_b))
			{
				rrb(stack_b);
			}
		}
		else
		{
			while ((*stack_b)->index != max_index(stack_b))
			{
				rb(stack_b);
			}
		}
		if ((*stack_b)->index == max_index(stack_b))
		{
			pa(stack_b, stack_a);
		}
				i++;
	}
}

void	chunk_check(t_data **stack_a, t_data **stack_b, int end, int top)
{
	int	chunk_midpoint;

	chunk_midpoint = (end + top) / 2;
	if ((*stack_a)->index <= chunk_midpoint)
		pb(stack_a, stack_b);
	else
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
}

void	size_100(t_data **stack_a, t_data **stack_b)
{
	int	top;
	int	end;
	int	chunk_p;
	int	i;

	top = 0;
	end = (lst_size(*stack_a) / 5) - 1;
	chunk_p = lst_size(*stack_a) / 5;
	i = 0;
	if (*stack_a == NULL)
		return ;
	while (lst_size(*stack_a))
	{
		i = 0;
		while (i < chunk_p && lst_size(*stack_a))
		{
			if ((*stack_a)->index >= top && (*stack_a)->index <= end)
			{
				chunk_check(stack_a, stack_b, end, top);
				i++;
			}
			else
				ra(stack_a);
		}
		top += chunk_p;
		end += chunk_p;
	}
	while (lst_size(*stack_b))
	{
		largest_number(stack_b);
	}
}
