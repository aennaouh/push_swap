/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:20:16 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 02:14:01 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_check_5(t_data **stack_a, t_data **stack_b, int end, int top)
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

void	size_500(t_data **stack_a, t_data **stack_b)
{
	t_norm	norm;

	norm.top = 0;
	norm.end = (lst_size(*stack_a) / 5) - 1;
	norm.chunk_p = lst_size(*stack_a) / 5;
	norm.i = 0;
	if (*stack_a == NULL)
		return ;
	while (lst_size(*stack_a))
	{
		norm.i = 0;
		while (norm.i < norm.chunk_p && lst_size(*stack_a))
		{
			if ((*stack_a)->index >= norm.top && (*stack_a)->index <= norm.end)
			{
				chunk_check_5(stack_a, stack_b, norm.end, norm.top);
				norm.i++;
			}
			else
				ra(stack_a);
		}
		norm.top += norm.chunk_p;
		norm.end += norm.chunk_p;
	}
	while (lst_size(*stack_b))
	{
		largest_number_5(stack_b);
	}
}
