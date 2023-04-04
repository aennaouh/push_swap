/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:04:44 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 04:32:59 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_data *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	print_stack(t_data *stack)
{
	t_data	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		printf ("%d |", tmp->content);
		tmp = tmp->next;
	}
}

//python3 data.py
//printf ("index :|%d |" "|content: %d\n |" "|inside: %d |",
//tmp->index ,tmp->content, tmp->inside);
// int	ft_get_indice_5(t_data *stack_b, int index)
// {
// 	int		indice;
// 	t_data	*tmp;

// 	tmp = (stack_b);
// 	indice = 0;
// 	while (tmp)
// 	{
// 		if (tmp->index == index)
// 			return (indice);
// 		indice++;
// 		tmp = tmp->next;
// 	}
// 	return (indice);
// }

// int	get_instr_5(t_data *stack_b, int index)
// {
// 	t_data	*tmp;
// 	int		count;
// 	int		indice;

// 	tmp = (stack_b);
// 	count = 0;
// 	indice = 0;
// 	while (tmp)
// 	{
// 		if (tmp->index == index)
// 		{
// 			indice = ft_get_indice_5(stack_b, index);
// 			if (indice <= lst_size(stack_b) / 2 && indice)
// 				count = indice;
// 			else if (indice > lst_size(stack_b) / 2 && indice)
// 				count = lst_size(stack_b) - indice + 1;
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (count);
// }

// void	largest_number_5(t_data **stack_b)
// {
// 	t_data	**stack_a;
// 	int		pos;
// 	int		pos1;
// 	int		i;
// 	int		flg;

// 	flg = 0;
// 	stack_a = NULL;
// 	i = 0;
// 	if (get_instr_5(*stack_b, max_index_5(stack_b)) < 
// 	get_instr_5(*stack_b, secand_index_5(stack_b)))
// 	{
// 		while (i < lst_size(*stack_b))
// 		{
// 			pos = pos_max_5(stack_b);
// 			if (pos > lst_size(*stack_b) / 2)
// 			{
// 				while ((*stack_b)->index != max_index_5(stack_b))
// 				{
// 					rrb(stack_b);
// 				}
// 			}
// 			else
// 			{
// 				while ((*stack_b)->index != max_index_5(stack_b))
// 				{
// 					rb(stack_b);
// 				}
// 			}
// 			if ((*stack_b)->index == max_index_5(stack_b))
// 			{
// 				break ;
// 			}
// 				i++;
// 		}
// 		if (stack_a && *stack_a && stack_b && *stack_b)
// 		{
// 			if (stack_a && *stack_a && stack_b && *stack_b && 
// 			(*stack_a)->content > (*stack_b)->content)
// 				ra(stack_a);
// 		}
// 		pa(stack_b, stack_a);
// 		if (stack_a && *stack_a && lst_size(*stack_a) > 1)
// 		{
// 			if (stack_a && *stack_a && 
// 			(*stack_a)->content > (*stack_a)->next->content)
// 				sa(stack_a);
// 		}
// 	}
// 	else
// 	{
// 		while (i < lst_size(*stack_b))
// 		{
// 			pos1 = pos_secand_5(stack_b);
// 			if (pos1 > lst_size(*stack_b) / 2)
// 			{
// 				while ((*stack_b)->index != secand_index_5(stack_b))
// 				{
// 					rrb(stack_b);
// 				}
// 			}
// 			else
// 			{
// 				while ((*stack_b)->index != secand_index_5(stack_b))
// 				{
// 					rb(stack_b);
// 				}
// 			}
// 			i++;
// 			if ((*stack_b)->index == secand_index_5(stack_b))
// 			{
// 				break ;
// 			}
// 		}
// 		if (stack_a && *stack_a 
// 		&& stack_b && *stack_b && lst_size(*stack_a) > 1)
// 		{
// 			if (stack_a && *stack_a && stack_b 
// 			&& *stack_b && (*stack_a)->content > (*stack_b)->content)
// 				ra(stack_a);
// 		}
// 		pa(stack_b, stack_a);
// 		if (stack_a && *stack_a && lst_size(*stack_a) > 1)
// 		{
// 			if (stack_a && *stack_a && 
// 			(*stack_a)->content > (*stack_a)->next->content)
// 				sa(stack_a);
// 		}
// 	}
// }

// void	chunk_check_5(t_data **stack_a, t_data **stack_b, int end, int top)
// {
// 	int	chunk_midpoint;

// 	chunk_midpoint = (end + top) / 2;
// 	if ((*stack_a)->index <= chunk_midpoint)
// 		pb(stack_a, stack_b);
// 	else
// 	{
// 		pb(stack_a, stack_b);
// 		rb(stack_b);
// 	}
// }

// void	size_500(t_data **stack_a, t_data **stack_b)
// {
// 	int	top;
// 	int	end;
// 	int	chunk_p;
// 	int	i;

// 	top = 0;
// 	end = (lst_size(*stack_a) / 10) - 1;
// 	chunk_p = lst_size(*stack_a) / 10;
// 	i = 0;
// 	if (*stack_a == NULL)
// 		return ;
// 	while (lst_size(*stack_a))
// 	{
// 		i = 0;
// 		while (i < chunk_p && lst_size(*stack_a))
// 		{
// 			if ((*stack_a)->index >= top && (*stack_a)->index <= end)
// 			{
// 				chunk_check_5(stack_a, stack_b, end, top);
// 				i++;
// 			}
// 			else
// 				ra(stack_a);
// 		}
// 		top += chunk_p;
// 		end += chunk_p;
// 	}
// 	while (*stack_b)
// 	{
// 		largest_number_5(stack_b);
// 	}
// }