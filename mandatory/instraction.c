/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:53:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/06 07:17:17 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data **stack_a)
{
	t_data	*tmp;

	if (!stack_a || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	(*stack_a) = tmp->next;
	tmp->next = tmp->next->next;
	(*stack_a)->next = tmp;
	ft_putstr("sa\n");
}

void	sb(t_data **stack_b)
{
	t_data	*tmp;

	if (!stack_b || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = tmp->next;
	tmp->next = tmp->next->next;
	(*stack_b)->next = tmp;
	ft_putstr("sb\n");
}

void	ss(t_data **stack_b, t_data **stack_a)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr("ss\n");
}

void	pa(t_data **stack_b, t_data **stack_a)
{
	t_data	*tmp;

	if (stack_b == NULL || (*stack_b) == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr("pa\n");
}

void	pb(t_data **stack_a, t_data **stack_b)
{
	t_data	*tmp;

	if (stack_a == NULL || (*stack_a) == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr("pb\n");
}
