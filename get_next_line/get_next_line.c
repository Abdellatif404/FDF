/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:44:38 by ael-bouz          #+#    #+#             */
/*   Updated: 2023/12/21 15:11:27 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_the_rest(char *str)
{
	char	*rest;
	size_t	len;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), (NULL));
	rest = malloc((len - i) * sizeof(char));
	ft_strlcpy(rest, str + i + 1, len - i);
	free(str);
	return (rest);
}

static char	*isolate_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, i + 1);
	return (line);
}

static char	*read_line(int fd, char *line)
{
	char		*buffer;
	ssize_t		rd;
	ssize_t		i;

	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	rd = 1;
	i = 0;
	if (!buffer)
		return (NULL);
	while (rd != 0 && !(has_newline(line)))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (free(buffer), free(line), (NULL));
		buffer[rd] = '\0';
		if (rd > 0)
			line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = isolate_line(buffer);
	buffer = get_the_rest(buffer);
	return (line);
}
