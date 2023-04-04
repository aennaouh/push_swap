/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilise3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:48:45 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 02:52:31 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
