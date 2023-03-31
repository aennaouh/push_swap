/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers500.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 05:20:16 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/30 02:06:21 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_indice_5(t_data *stack_b, int index)
{
	int		indice;
	t_data	*tmp;

	tmp = (stack_b);
	indice = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (indice);
		indice++;
		tmp = tmp->next;
	}
	return (indice);
}

int	get_instr_5(t_data *stack_b, int index)
{
	t_data	*tmp;
	int		count;
	int		indice;

	tmp = (stack_b);
	count = 0;
	indice = 0;
	while (tmp)
	{
		if (tmp->index == index)
		{
			indice = ft_get_indice_5(stack_b, index);
			if (indice <= lst_size(stack_b) / 2 && indice)
				count = indice;
			else if (indice > lst_size(stack_b) / 2 && indice)
				count = lst_size(stack_b) - indice + 1;
		}
		tmp = tmp->next;
	}
	return (count);
}

void	largest_number_5(t_data **stack_b)
{
	t_data	**stack_a;
	int		pos;
	int		pos1;
	int		i;

	stack_a = NULL;
	i = 0;
	if (get_instr_5(*stack_b, max_index_5(stack_b)) < \
	get_instr_5(*stack_b, secand_index_5(stack_b)))
	{
		while (i < lst_size(*stack_b))
		{
			pos = pos_max_5(stack_b);
			if (pos > lst_size(*stack_b) / 2)
			{
				while ((*stack_b)->index != max_index_5(stack_b))
				{
					rrb(stack_b);
				}
			}
			else
			{
				while ((*stack_b)->index != max_index_5(stack_b))
				{
					rb(stack_b);
				}
			}
			if ((*stack_b)->index == max_index_5(stack_b))
			{
				pa(stack_b, stack_a);
			}
				i++;
		}
	}
	else
	{
		while (i < lst_size(*stack_b))
		{
			pos1 = pos_secand_5(stack_b);
			if (pos1 > lst_size(*stack_b) / 2)
			{
				while ((*stack_b)->index != secand_index_5(stack_b))
				{
					rrb(stack_b);
				}
			}
			else
			{
				while ((*stack_b)->index != secand_index_5(stack_b))
				{
					rb(stack_b);
				}
			}
			if ((*stack_b)->index == secand_index_5(stack_b))
			{
				pa(stack_b, stack_a);
			}
			i++;
		}
	}
}

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
	int	top;
	int	end;
	int	chunk_p;
	int	i;

	top = 0;
	end = (lst_size(*stack_a) / 10) - 1;
	chunk_p = lst_size(*stack_a) / 10;
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
				chunk_check_5(stack_a, stack_b, end, top);
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
		largest_number_5(stack_b);
	}
}
