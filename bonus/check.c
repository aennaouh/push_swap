/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/01 03:08:23 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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

t_data	*int_insid(char **str, int num)
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
	return (stack_a);
}

void	check_if_sorted(t_data *stack_a)
{
	int		i;
	t_data	*tmp;

	i = 1;
	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->content < tmp->next->content)
		{
			//printf("c: %d\tn: %d\n", tmp->content, tmp->next->content);
			i++;
		}
		tmp = tmp->next;
	}
	if (i == lst_size(stack_a))
	{
		ft_putstr("ok\n");
		exit(1);
	}
	else
	{
		ft_putstr("ko\n");
		exit(1);
	}
}

void	read_instructions(t_data **stack_a, t_data **stack_b)
{
	char	*tab;

	tab = get_next_line(0);
	while (tab)
	{
		if (ft_strcmp(tab, "sa\n"))
			sa (stack_a);
		else if (ft_strcmp(tab, "ra\n"))
			ra (stack_a);
		else if (ft_strcmp(tab, "rra\na"))
			rra (stack_a);
		else if (ft_strcmp(tab, "pb\n"))
			pb (stack_b, stack_a);
		else if (ft_strcmp(tab, "pa\n"))
			pa (stack_a, stack_b);
		else if (ft_strcmp(tab, "rb\n"))
			rb (stack_b);
		else if (ft_strcmp(tab, "rrb\n"))
			rrb (stack_b);
		else if (ft_strcmp(tab, "rra\n"))
			rra (stack_b);
		else if (ft_strcmp(tab, "rrr\n"))
			rrr (stack_b, stack_a);
		else
		{
			write(2, "Error:\n", 7);
			//free(stack_a) 
			exit(1);
		}
		tab = get_next_line(0);
		free(tab);
	}
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
	int		i;
	char	**split;
	char	*join;
	t_data	*stack_a;
	t_data	*stack_b;
	t_data	*stack_a_bonus;
	int		num;

	stack_a_bonus = NULL;
	stack_a = NULL;
	stack_b = NULL;
	num = 0;
	split = NULL;
	i = 1;
	if (argc == 1)
		return (1);
	if (argc > 1)
	{
		i = 1;
		join = ft_strdpp(" ");
		while (argv[i])
		{
			join = ft_strjoin(join, " ");
			join = ft_strjoin(join, argv[i]);
			i++;
			num++;
		}
		split = ft_split(join, ' ');
	}
	check_duplicat(split);
	check_integer(split);
	check_bigger(split);
	stack_a_bonus = int_insid(split, num);
	check_if_sorted(stack_a);
}
