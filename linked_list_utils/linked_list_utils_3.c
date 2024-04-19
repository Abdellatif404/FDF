/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:10:14 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/03/14 13:54:15 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*current;

	if (!lst)
		return (FAILURE);
	size = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int	ft_lstgrep(t_list *lst, int place)
{
	t_list	*current;
	int		i;

	if (!lst)
		return (FAILURE);
	current = lst;
	i = 1;
	while (current && i != place)
	{
		i++;
		current = current->next;
	}
	return (current->data);
}

int	ft_lstfind(t_list *lst, int n)
{
	int		place;
	t_list	*current;

	if (!lst)
		return (FAILURE);
	place = 0;
	current = lst;
	while (current)
	{
		place++;
		if (current->data == n)
			break ;
		current = current->next;
	}
	if (current && current->data == n)
		return (place);
	return (0);
}

int	is_sorted(t_list *lst)
{
	t_list	*current;
	t_list	*current2;
	int		place;
	int		i;

	if (!lst)
		return (FAILURE);
	current = lst;
	place = 0;
	while (current)
	{
		current2 = lst;
		i = 0;
		while (i < place)
		{
			if (current2->data > current->data)
				return (FAILURE);
			i++;
			current2 = current2->next;
		}
		current = current->next;
		place++;
	}
	return (SUCCESS);
}
*/