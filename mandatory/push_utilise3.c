/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilise3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:59:07 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/11 02:26:58 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **split)
{
	int	j;

	j = 0;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

void	free_stack(t_data *stack)
{
	t_data	*node;

	while (stack != NULL)
	{
			node = stack;
			stack = stack->next;
		free(node);
	}
}

int	find_index(t_data *stack_a, int the_smallest)
{
	int			i;
	t_data		*temp;

	i = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->index == the_smallest)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

void	index_size(t_data *stack_a)
{
	t_data	*tmpi;
	t_data	*tmpj;
	int		index;

	tmpi = stack_a;
	if (stack_a == NULL)
		return ;
	while (tmpi != NULL)
	{
	tmpj = stack_a;
		index = 0;
		while (tmpj != NULL)
		{
			if (tmpj->content != tmpi->content && tmpi->content > tmpj->content)
				index++;
			tmpj = tmpj->next;
		}
		tmpi->index = index;
		tmpi = tmpi->next;
	}
}
