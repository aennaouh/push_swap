/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:02:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/09 23:34:12 by aennaouh         ###   ########.fr       */
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

void	int_unsid(char **str)
{
	t_data	*stack_a;
	t_data	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (str[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[i])));
			i++;
	}
	index_size(stack_a);
	read_instructions(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

void ff(void)
{
	system("leaks checker");
}
int	main(int argc, char **argv)
{
	t_norm	norm;

	init(&norm);
	if (argc == 1)
		return (1);
	check_empty_spaces(argv);
	if (argc > 1)
	{
		norm.i = 1;
		norm.join = ft_strdpp("");
		while (argv[norm.i])
		{
			norm.join = ft_strjoin2(norm.join, " ");
			norm.join = ft_strjoin2(norm.join, argv[norm.i]);
			norm.i++;
			norm.num ++;
		}
		norm.split = ft_split(norm.join, ' ');
		free(norm.join);
	}
	suite_main(norm.split);
	free_all(norm.split);
	atexit(ff);
}
