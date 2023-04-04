/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 06:37:00 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/03 08:45:43 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_data **stack_a)
{
	t_data	*tmp;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next->next = (*stack_a);
	*stack_a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_data **stack_b)
{
	t_data	*tmp;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next->next = (*stack_b);
	*stack_b = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_data **stack_b, t_data **stack_a)
{
	rra(stack_a);
	rrb(stack_b);
}
