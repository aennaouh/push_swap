/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/31 06:30:28 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

// void check_if_sorted(t_data **stack_a)
// {
//        int i = 1;
//        t_data *tmp;
       
//        tmp= *stack_a;
    
//        while(tmp && tmp->next);
//        {
//         if(tmp->content < tmp->next->content)
//             i++;
//        }
//         if(i == lst_size(*stack_a))
//         printf("SUUUUIII"); 
// }

void read_instructions(t_data **stack_a, t_data **stack_b)
{
    char *tab;
    int i = 0;
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
		else if(ft_strcmp(tab, "pa\n"))
		pa(stack_a, stack_b);
        tab = get_next_line(0);
        i++;
        free(tab);
    }
    
}

// void	int_insid(char **str, int num)
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
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;
	char	*join;
	t_data	*stack_a;
	t_data	*stack_b;
	t_data	*stack_a_bonus = NULL;
	int		num;

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
		while (argv[i])
		{
			if (!join)
				join = "";
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
	int_insid(split, num);
    check_if_sorted(stack_a);
}
