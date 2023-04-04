/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 02:46:41 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

t_data	*int_unsid(char **str, int num)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (i < num)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[i])));
			i++;
	}
	index_size(stack_a);
	read_instructions(&stack_a, &stack_b);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_norm	norm;

	init(&norm);
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		norm.i = 1;
		norm.join = ft_strdup3(" ");
		while (argv[norm.i])
		{
			norm.join = ft_strjoi(norm.join, " ");
			norm.join = ft_strjoi(norm.join, argv[norm.i]);
			norm.i++;
			norm.num ++;
		}
		norm.split = ft_split(norm.join, ' ');
	}
	index_size(norm.stack_a);
	suite_main(norm.split, norm.num);
	size_check(&norm.stack_a, &norm.stack_b);
}
