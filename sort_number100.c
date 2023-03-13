/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number100.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:54:04 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/13 01:37:46 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_100(t_data **stack_a)
{
	int		check_top;
	int		check_midpoint;
	int		check_end;
	t_data	*current;
	t_data	*stack_b;

	stack_b = NULL;
	if ((*stack_a) == NULL)
		return ;
	while (lst_size((*stack_a)) / 5)
	{
		if ((*stack_a)->index >= 5 && (*stack_a)->index <= 19)
		{
			check_top = 0;
			check_end = 19;
			check_midpoint = (check_top + check_end) / 2;
			current = (*stack_a);
			while (current != NULL)
			{
	

				if (current->index < check_midpoint)
				{
					pb(&current, &stack_b);
					ra(&current);
					printf("inside:%d\n", current->);
				}
				else
				{
					pb(&current, &stack_b);
					ra(stack_a);
				}
		current = current->next;
			}
		}
	check_top = check_top + 20;
	check_end = check_end + 20;
	}
}
