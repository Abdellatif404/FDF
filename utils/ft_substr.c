/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:04:29 by ael-bouz          #+#    #+#             */
/*   Updated: 2023/11/07 21:04:29 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * ft_substr - Allocates a substring.
 * @s: the string from which to create the substring.
 * @start: the start index of the substring in the string ’s’.
 * @len: the maximum length of the substring.
 * Return: the substring or NULL if the allocation fails.
 */

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s) - start;
	if (start > ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	return (ptr);
}
