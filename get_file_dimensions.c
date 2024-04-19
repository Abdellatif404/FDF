/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_dimensions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:34:34 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 15:48:29 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_values(int *fd, char *filename, char **buff)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == FAILURE)
		return (FAILURE);
	*buff = malloc((10000 + 1) * sizeof(char));
	if (!(*buff))
		return (free_if_and_close(NULL, *buff, *fd));
	return (SUCCESS);
}

int	read_buffer(int *rd, int fd, char *buff, char **line)
{
	*rd = read(fd, buff, 10000);
	if (*rd == FAILURE)
		return (free_if_and_close(*line, buff, fd));
	buff[*rd] = 0;
	*line = ft_strjoin(*line, buff);
	return (*rd);
}

int	count_width(char *line)
{
	int		i;
	char	*first_line;
	char	**tab;

	i = 0;
	if (!line)
		return (FAILURE);
	while (line[i] && line[i] != '\n')
		i++;
	first_line = ft_substr(line, 0, i);
	tab = ft_split(first_line, ' ');
	if (!tab)
	{
		if (first_line)
			free(first_line);
		return (FAILURE);
	}
	i = 0;
	while (tab[i])
		i++;
	free(first_line);
	free_array(tab);
	return (i);
}

int	get_file_width(char *filename, int *file_width)
{
	int		fd;
	char	*buff;
	int		rd;
	int		width;
	char	*line;

	if (init_values(&fd, filename, &buff) == FAILURE)
		return (FAILURE);
	rd = 1;
	line = NULL;
	while (rd != 0)
	{
		rd = read_buffer(&rd, fd, buff, &line);
		if (rd == FAILURE)
			return (FAILURE);
		width = count_width(line);
		if (width == FAILURE)
			return (free_if_and_close(line, buff, fd));
		*file_width += width;
		if (has_newline(line) == 1)
			break ;
	}
	free_if_and_close(line, buff, fd);
	return (width);
}

int	count_newlines(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	get_file_height(char *filename, int *file_height)
{
	int		fd;
	char	*buff;
	int		rd;

	fd = open(filename, O_RDONLY);
	if (fd == FAILURE)
		return (FAILURE);
	buff = malloc((10000 + 1) * sizeof(char));
	if (!buff)
		return (free_if_and_close(NULL, buff, fd));
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, 10000);
		if (rd == FAILURE)
			return (free_if_and_close(NULL, buff, fd));
		buff[rd] = 0;
		*file_height += count_newlines(buff);
	}
	free_if_and_close(NULL, buff, fd);
	return (SUCCESS);
}

void	get_file_dimensions(char *filename, t_mlx *data)
{
	int	file_width;
	int	file_height;

	data->shape_width = 0;
	data->shape_height = 0;
	file_width = get_file_width(filename, &data->shape_width);
	file_height = get_file_height(filename, &data->shape_height);
	if (file_width == FAILURE || file_height == FAILURE)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
}
