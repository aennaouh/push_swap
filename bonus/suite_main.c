/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:45:52 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/10 05:21:59 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_empty(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}

void	check_empty_spaces(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (is_empty(str[i]) == 1)
		{
			write(2, "Error:\nEmpty String.\n", 21);
			exit(1);
		}
		i++;
	}
}

void	suite_main(char **split)
{
	check_duplicat(split);
	check_integer(split);
	check_bigger(split);
	int_unsid(split);
}

void	suite_free(t_data *stack_a, t_data *stack_b, char **split)
{
	free_all(split);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	init(t_norm *norm)
{
	norm->stack_a = NULL;
	norm->join = NULL;
	norm->split = NULL;
	norm->i = 0;
	norm->stack_b = NULL;
	norm->join = NULL;
	norm->i = 1;
}
