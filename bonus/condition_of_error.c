/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_of_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:19:51 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/31 06:35:03 by aennaouh         ###   ########.fr       */
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
			write(2, "Error:\n arguments aren't integers", 33);
			exit(1);
		}
		while (str[i][j])
		{
			printf("\'%c\'\n", str[i][j]);
			if (!ft_isdigit(str[i][j]))
			{
				write(2, "Error:\n arguments aren't integers", 33);
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
		if (pid > INT_MAX)
		{
			write(2, "Error:\nbigger than an integer.\n", 31);
			exit(1);
		}
		else if (pid < INT_MIN)
		{
			write(2, "Error:\nlittle than an integer.\n", 31);
			exit(1);
		}
		i++;
	}
}

int	ft_strlen_lien(char **s)
{
	int	i;

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
				write(2, "Error:\n there are duplicates.\n", 30);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
