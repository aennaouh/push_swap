/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:54:58 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/04 02:51:50 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_words(char *s, char c)
{
	int	i;
	int	nw;

	i = 0;
	nw = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			nw++;
		}
	}
	return (nw);
}

static int	len_caracter(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	execute(char *s, char c, char **str)
{
	int		i;
	int		j;
	int		k;
	size_t	length;

	i = 0;
	j = -1;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		length = len_caracter(s + i, c) + 1;
		str[++j] = malloc(length * sizeof(char));
		if (str[j] == NULL)
			return (-1);
		while (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		str[j][k] = '\0';
	}
	return (0);
}

static void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	length;
	int		err;

	if (!s)
		return (NULL);
	length = ft_words((char *)s, c) + 1;
	str = ft_calloc(length, sizeof(char *));
	if (!str)
		return (NULL);
	err = execute((char *)s, c, str);
	if (err == -1)
		return (free_tab(str), NULL);
	return (str);
}
