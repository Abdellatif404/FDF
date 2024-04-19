/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:47:45 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 15:51:30 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	free_if_and_close(char *line, char *buff, int fd)
{
	if (line)
		free(line);
	if (buff)
		free(buff);
	close(fd);
	return (FAILURE);
}

int	free_line(char *line)
{
	if (line)
		free(line);
	return (FAILURE);
}

char	**free_array(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

void	*free_matrix(t_matrix **head)
{
	t_matrix	*row;
	t_matrix	*column;
	t_matrix	*tmp;

	row = *head;
	while (row)
	{
		column = row;
		row = row->down;
		while (column)
		{
			tmp = column;
			column = column->right;
			free(tmp);
		}
	}
	free(head);
	return (NULL);
}
