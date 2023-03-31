/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:04:44 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/31 06:21:57 by aennaouh         ###   ########.fr       */
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
		printf ("index :|%d |" "|content: %d\n |", tmp->index, tmp->content);
		tmp = tmp->next;
	}
	//printf("\n");
}

//python3 data.py
//printf ("index :|%d |" "|content: %d\n |" "|inside: %d |", tmp->index ,tmp->content, tmp->inside);