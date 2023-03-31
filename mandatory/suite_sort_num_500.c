/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_sort_num_500.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:17:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/29 22:18:15 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_secand_5(t_data **stack_b)
{
	t_data	*tmp;
	int		pos;
	int		index;

	pos = 0;
	tmp = (*stack_b);
	index = secand_index_5(stack_b);
	while (tmp != NULL)
	{
		if (tmp->index == secand_index_5(stack_b))
			return (pos);
			pos++;
		tmp = tmp->next;
	}
	return (0);
}

int	secand_index_5(t_data **stack_b)
{
	t_data	*tmp;
	int		secand;
	int		max;

	max = 0;
	secand = 0;
	tmp = (*stack_b);
	while (tmp != NULL)
	{
		if (tmp->index > max)
		{
			secand = max;
			max = tmp->index;
		}
		else if (tmp->index > secand && tmp->index < max)
		{
			secand = tmp->index;
		}
		tmp = tmp->next;
	}
	return (secand);
}

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
