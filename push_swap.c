/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:55:28 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/13 00:42:34 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_integer(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return ;
	
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (str[i][j] == '\0')
		{
			write(2, "Error:\n arguments aren't integers", 36);
			exit(1);
		}
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				write(2, "Error:\n arguments aren't integers", 36);
				exit(1);
			}
			j++;
		}
		i++;
	}
}


void	check_bigger(char **str)
{
	int		i;
	long	pid;

	i = 0;
	while (str[i])
	{
		pid = ft_atoi(str[i]);
		//printf("--%ld--\n", pid);
		if (pid > INT_MAX)
		{
			write(2, "Error:\nbigger than an integer.\n", 31);
			exit(1);
		}
		else if(pid < INT_MIN)
		{
			write(2, "Error:\nlittle than an integer.\n", 31);
			exit(1);
		}
		i++;
	}
}

int ft_strlen_lien(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	check_duplicat(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		j = i + 1;
		while (j < ft_strlen_lien(str))
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				write(2, "Error:\n there are duplicates.\n", 32);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	int_insid(char **str, int num)
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
	print_stack(stack_a);
	size_100(&stack_a);
	print_stack(stack_a);
}

int	main(int argc, char **argv)
{
	int		i;
	char 	**split;
	char	*join;
	t_data	*stack_a;
	t_data	*stack_b;
	int		num;
	
	stack_a = NULL;
	stack_b = NULL;
	num	= 0;
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
	int_insid(split, num);
	check_integer(split);
	check_duplicat(split);
	check_bigger(split);
 }
