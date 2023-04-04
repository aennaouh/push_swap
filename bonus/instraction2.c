/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:09:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/03 08:45:31 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_data **stack_a)
{
	t_data	*tmp;
	t_data	*tmp1;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	*stack_a = tmp->next;
	tmp1 = (*stack_a);
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp;
	tmp->next = NULL;
}

void	rb(t_data **stack_b)
{
	t_data	*tmp;
	t_data	*tmp1;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	*stack_b = tmp->next;
	tmp1 = (*stack_b);
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp;
	tmp->next = NULL;
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
