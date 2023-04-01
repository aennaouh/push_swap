/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilise1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:40:51 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/01 02:57:45 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoi(const char *s1, const char *s2)
{
	int		lent;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lent = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((lent + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j++] = '\0';
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

void	ft_putnber(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 1);
	}
	else if (n < 0)
	{
		ft_putnber(-n);
		write(1, "-", 1);
	}
	else if (n > 9)
	{
		ft_putnber(n / 10);
		ft_putnber(n % 10);
	}
	else
		c = n + '0';
	write (1, &c, 1);
}

char	*ft_strd(const char *s1)
{
	size_t	i;
	size_t	lent;
	char	*str;

	i = 0;
	lent = ft_strlen(s1);
	str = malloc ((lent + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < lent)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
