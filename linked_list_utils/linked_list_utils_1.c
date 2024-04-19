/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:00:32 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/03/14 13:53:57 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new || !lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
}

t_list	*ft_lstbefore_last(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next->next)
		current = current->next;
	return (current);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

void	display_list(t_list *node)
{
	t_list	*current;

	current = node;
	if (!current)
		return ;
	while (current)
	{
		printf("%d", current->data);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	**head;
	t_list	*node1, *node2, *node3;

	node1 = ft_lstnew(1);
	node2 = ft_lstnew(3);
	node3 = ft_lstnew(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	head = &node1;

	printf("The address of the node %p\n", node1);
	printf("The address of the data %p\n", &(node1->data) + 2);
	printf("size of next pointer %p\n", &(node1->next));
	display_list(*head);
	return (0);
}
*/