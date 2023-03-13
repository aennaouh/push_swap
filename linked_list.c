/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:54:17 by aennaouh          #+#    #+#             */
/*   Updated: 2023/03/12 10:58:05 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_lstnew(int content)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_data **lst, t_data *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_data *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->next++;
		i++;
	}
	return (i);
}

t_data	*ft_lstlast(t_data *lst)
{
	while (lst)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

void	ft_lstclear(t_data **lst, void (*del)(int))
{
	t_data	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		tmp->next = NULL;
		del(tmp->content);
		free(tmp);
	}
	*lst = NULL;
}
