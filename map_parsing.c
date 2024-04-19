/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:21:14 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 15:49:27 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line/get_next_line.h"

// t_matrix	*parse_line(t_matrix *node, char *buff)
// {
// 	int			i;
// 	t_matrix	*row;

// 	i = 0;
// 	row = node;
// 	while (buff[i] && buff[i] != '\n')
// 	{
// 		node->z = ft_atoi(buff + i);
// 		while (buff[i] && buff[i] != ',' && buff[i] != ' ' && buff[i] != '\n')
// 			i++;
// 		if (buff[i] == ',' && buff[i + 1] == '0')
// 		{
// 			node->color = ft_htoi(buff + i + 3);
// 			while (buff[i] && buff[i] != ',' && buff[i] != ' ' && buff[i] != '\n')
// 				i++;
// 		}
// 		if (node->z != 0)
// 			node->color = 0x000000;
// 		node = node->right;
// 		i++;
// 	}
// 	row = row->down;
// 	return (row);
// }

// int	last_pnt_idx(char *buff)
// {
// 	int	len;

// 	len = ft_strlen(buff) - 1;
// 	if (len >= 0 && buff[len] != ' ' && buff[len] != '\n')
// 	{
// 		while (len >= 0 && buff[len] != ' ' && buff[len] != '\n')
// 		{
// 			len--;
// 		}
// 		return (len);
// 	}
// 	return (-1);
// }

// int	parse_map(char *filename, t_matrix **head)
// {
// 	int			fd;
// 	int			rd;
// 	int			index;
// 	char		*buff;
// 	t_matrix	*node;

// 	fd = open(filename, O_RDONLY);
// 	rd = 1;
// 	buff = malloc(10 + 1 * sizeof(char));
// 	node = *head;
// 	while (rd)
// 	{
// 		rd = read(fd, buff, 10);
// 		buff[rd] = 0;
// 		index = last_pnt_idx(buff);
// 		if (index == -1)
// 		{
// 			while (node)
// 			{
// 				node = parse_line(node, buff);
// 			}
// 		}
// 		// printn(buff);
// 	}
// 	return (SUCCESS);
// }

// void printStringArray(char **tab) {
//     int i = 0;
//     while (tab[i] != NULL) {
//         printf("%s ", tab[i]);
//         i++;
//     }
//     printf("\n");
// }

static void	parse_line(t_matrix *node, char **tab, int test)
{
	int	i;
	int	j;

	i = 0;
	while (node && tab[i])
	{
		j = 0;
		node->z = ft_atoi(tab[i]);
		while (tab[i][j] != ',' && tab[i][j])
			j++;
		if (tab[i][j] == ',' && tab[i][j + 1] == '0')
		{
			j += 3;
			node->red = ft_htoi(tab[i] + j);
			node->green = 0;
			node->blue = 0;
			j += 2;
			if (tab[i][j])
			{
				node->green = ft_htoi(tab[i] + j);
				j += 2;
			}
			if (tab[i][j])
				node->blue = ft_htoi(tab[i] + j);
			// node->color = ft_htoi(tab[i] + j + 3);
		}
		if (test == 3 && i == 0)
		{
			// printf("%d -> (%d, %d, %d)\n", node->z, node->red, node->green, node->blue);
			// printStringArray(tab);
		}
		node = node->right;
		i++;
	}
}

int	parse_map(char *filename, t_matrix **head)
{
	char		**tab;
	char		*line;
	t_matrix	*node;
	int			fd;
	int	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == FAILURE)
		return (FAILURE);
	node = *head;
	while (node)
	{
		i++;
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		if (!tab)
			return (free_line(line));
		parse_line(node, tab, i);
		free(line);
		free_array(tab);
		node = node->down;
	}
	close(fd);
	return (SUCCESS);
}

// void	printn(char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	printf("buff: [");
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 		{
// 			putchar('\\');
// 			putchar('n');
// 		}
// 		else
// 			putchar(s[i]);
// 		i++;
// 	}
// 	printf("] -> ");
// 	printf("index: %d\n", last_pnt_idx(s));
// }