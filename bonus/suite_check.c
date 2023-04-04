/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:42:54 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/03 20:12:34 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	read_instructions(t_data **stack_a, t_data **stack_b)
{
	char	*tab;

	tab = get_next_line(0);
	while (tab)
	{
		if (ft_strcmp(tab, "sa\n") == 0)
			sa (stack_a);
		else if (ft_strcmp(tab, "ss\n") == 0)
			ss (stack_b, stack_a);
		else if (ft_strcmp(tab, "ra\n") == 0)
			ra (stack_a);
		else if (ft_strcmp(tab, "rr\n") == 0)
			rr (stack_a, stack_b);
		else if (ft_strcmp(tab, "rra\n") == 0)
			rra (stack_a);
		else if (ft_strcmp(tab, "pb\n") == 0)
			pb (stack_b, stack_a);
		else if (ft_strcmp(tab, "pa\n") == 0)
			pa (stack_a, stack_b);
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
			exit(0);
		}
		free(tab);
		tab = get_next_line(0);
	}
	if (check_if_sorted(*stack_a) == 0)
	{
		ft_putstr("ok\n");
	}
	else
		ft_putstr("ko\n");
}

int	check_if_sorted(t_data *stack_a)
{
	int		i;
	t_data	*tmp;

	i = 1;
	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->content < tmp->next->content)
		{
			i++;
		}
		tmp = tmp->next;
	}
	if (i == lst_size(stack_a))
		return (0);
	return (1);
}
