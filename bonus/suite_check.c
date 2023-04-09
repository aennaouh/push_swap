/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:42:54 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/09 23:40:17 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	suit_read_instructions(t_data **stack_a, t_data **stack_b, char *tab)
{
	if (ft_strcmp(tab, "ss\n") == 0)
		ss (stack_b, stack_a);
	else if (ft_strcmp(tab, "ra\n") == 0)
		ra (stack_a);
	else if (ft_strcmp(tab, "rr\n") == 0)
		rr (stack_a, stack_b);
	else if (ft_strcmp(tab, "rra\n") == 0)
		rra (stack_a);
	else if (ft_strcmp(tab, "sa\n") == 0)
		sa (stack_a);
	else if (ft_strcmp(tab, "pa\n") == 0)
		pa (stack_b, stack_a);
	else if (ft_strcmp(tab, "rb\n") == 0)
		rb (stack_b);
	else if (ft_strcmp(tab, "rrb\n") == 0)
		rrb (stack_b);
	else if (ft_strcmp(tab, "sb\n") == 0)
		sb (stack_b);
	else if (ft_strcmp(tab, "rrr\n") == 0)
		rrr (stack_b, stack_a);
	else
	{
		write(2, "Error\n", 7);
		free_stack(*stack_b);
		//free_stack(*stack_a);
		exit(1);
	}
}

void	read_instructions(t_data *stack_a, t_data *stack_b)
{
	char	*tab;

	tab = get_next_line(0);
	while (tab)
	{
		if (ft_strcmp(tab, "pb\n") == 0)
			pb (&stack_a, &stack_b);
		else
			suit_read_instructions(&stack_a, &stack_b, tab);
		free(tab);
		tab = get_next_line(0);
	}
	//free(tab);
	if (check_sorted(&stack_a) && stack_b == NULL)
	{
		ft_putstr("OK\n");
	}
	else
		ft_putstr("KO\n");
}

int	check_sorted(t_data **stack_a)
{
	t_data	*tmp;

	tmp = (*stack_a);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
