/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:33:09 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/29 17:23:10 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_matrix	*create_node(int x, int y)
{
	t_matrix	*node;

	node = malloc(sizeof(t_matrix));
	if (!node)
		return (NULL);
	node->x_idx = x;
	node->y_idx = y;
	node->x = 0;
	node->y = 0;
	node->z = 0;
	node->red = 0xff;
	node->green = 0xff;
	node->blue = 0xff;
	node->right = NULL;
	node->down = NULL;
	return (node);
}

static void	connect_row(t_matrix *ptrs[3], int x)
{
	if (x == 0)
	{
		ptrs[1] = (ptrs[0])->down;
		ptrs[2] = (ptrs[0])->down;
	}
	else
	{
		(ptrs[2])->right = (ptrs[0])->down;
		ptrs[2] = (ptrs[2])->right;
	}
}

int	create_right_node(int coords[2], int width, t_matrix *ptrs[3])
{
	if (coords[0] < width - 1 && coords[1] == 0)
	{
		ptrs[0]->right = create_node(coords[0] + 1, coords[1]);
		if (!(ptrs[0]->right))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	create_down_node(int coords[2], int height, t_matrix *ptrs[3])
{
	if (coords[1] < height - 1)
	{
		ptrs[0]->down = create_node(coords[0], coords[1] + 1);
		if (!(ptrs[0]->down))
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	create_nodes(t_matrix **head, int height, int width)
{
	t_matrix	*ptrs[3];
	int			coords[2];

	ptrs[0] = *head;
	ptrs[1] = NULL;
	ptrs[2] = NULL;
	coords[0] = 0;
	coords[1] = 0;
	while (coords[1] < height - 1)
	{
		coords[0] = 0;
		while (coords[0] < width)
		{
			if (create_right_node(coords, width, ptrs) == FAILURE)
				return (FAILURE);
			if (create_down_node(coords, height, ptrs) == FAILURE)
				return (FAILURE);
			connect_row(ptrs, coords[0]);
			ptrs[0] = ptrs[0]->right;
			coords[0]++;
		}
		ptrs[0] = ptrs[1];
		coords[1]++;
	}
	return (SUCCESS);
}

t_matrix	**create_matrix(t_mlx *data)
{
	t_matrix	**head;

	head = malloc(sizeof(t_matrix *));
	if (!head)
		return (NULL);
	*head = create_node(0, 0);
	if (!(*head))
		return (free_matrix(head));
	data->steps = 50;
	(*head)->x = WIN_WIDTH / 2 - ((data->shape_width - 1) * data->steps / 2);
	(*head)->y = WIN_HEIGHT / 2 - ((data->shape_height - 1) * data->steps / 2);
	if (create_nodes(head, data->shape_height, data->shape_width) == FAILURE)
		return (free_matrix(head));
	return (head);
}
