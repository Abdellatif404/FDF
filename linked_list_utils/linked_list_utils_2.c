/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:17:10 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/03/14 13:54:07 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

int	ft_lstmin(t_list *lst)
{
	t_list	*current;
	int		i;
	int		min;
	int		min_place;

	if (!lst)
		return (FAILURE);
	current = lst;
	i = 1;
	min = lst->data;
	min_place = 1;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			min_place = i;
		}
		i++;
		current = current->next;
	}
	return (min_place);
}

int	ft_lstmax(t_list *lst)
{
	t_list	*current;
	int		i;
	int		max;
	int		max_place;

	if (!lst)
		return (FAILURE);
	current = lst;
	i = 1;
	max = lst->data;
	max_place = 1;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			max_place = i;
		}
		i++;
		current = current->next;
	}
	return (max_place);
}

int	find_lower(t_list *lst, int n)
{
	int		i;
	int		first_occurence;
	int		closest_lower;
	int		closest_lower_place;

	i = 0;
	first_occurence = 0;
	closest_lower_place = 0;
	while (lst)
	{
		i++;
		if (!first_occurence && lst->data < n)
		{
			closest_lower = lst->data;
			closest_lower_place = i;
			first_occurence = 1;
		}
		else if (lst->data < n && lst->data > closest_lower)
		{
			closest_lower = lst->data;
			closest_lower_place = i;
		}
		lst = lst->next;
	}
	return (closest_lower_place);
}

int	find_higher(t_list *lst, int n)
{
	int		i;
	int		first_occurence;
	int		closest_higher;
	int		closest_higher_place;

	i = 0;
	first_occurence = 0;
	closest_higher_place = 0;
	while (lst)
	{
		i++;
		if (!first_occurence && lst->data > n)
		{
			closest_higher = lst->data;
			closest_higher_place = i;
			first_occurence = 1;
		}
		else if (lst->data > n && lst->data < closest_higher)
		{
			closest_higher = lst->data;
			closest_higher_place = i;
		}
		lst = lst->next;
	}
	return (closest_higher_place);
}
*/