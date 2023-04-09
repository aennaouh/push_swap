/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:58:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/06 02:30:37 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_norm	norm;

	norm.top = 0;
	norm.end = (lst_size(*stack_a) / 5) - 1;
	norm.chunk_p = lst_size(*stack_a) / 5;
	if (*stack_a == NULL)
		return ;
	while (lst_size(*stack_a))
	{
		norm.i = 0;
		while (norm.i < norm.chunk_p && lst_size(*stack_a))
		{
			if ((*stack_a)->index >= norm.top && (*stack_a)->index <= norm.end)
			{
				chunk_check(stack_a, stack_b, norm.end, norm.top);
				norm.i++;
			}
			else
				ra(stack_a);
		}
		norm.top += norm.chunk_p;
		norm.end += norm.chunk_p;
	}
	while (lst_size(*stack_b))
		largest_number(stack_a, stack_b);
}
