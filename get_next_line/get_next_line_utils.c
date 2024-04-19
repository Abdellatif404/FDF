/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:18:55 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/11 11:28:33 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	dup = malloc((len + 1) * sizeof(char));
	if (dup)
	{
		while (len >= 0)
		{
			dup[len] = s1[len];
			if (!len)
				break ;
			len--;
		}
	}
	return (dup);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (dstsize > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	l1;
	size_t	l2;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc((l1 + l2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, l1 + 1);
	free(s1);
	ft_strlcpy(ptr + l1, s2, l2 + 1);
	return (ptr);
}
