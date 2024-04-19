/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:03:34 by ael-bouz          #+#    #+#             */
/*   Updated: 2023/11/12 15:03:34 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * count_words - Count the number of words in a string based on a delimiter.
 * @s: the string to be analyzed.
 * @delimiter: the character used as the delimiter to identify words.
 * Return: the number of words found in the string.
 */

static size_t	count_words(char const *s, char delimiter)
{
	size_t		i;
	short int	word_found;
	int			words_count;

	i = 0;
	word_found = 0;
	words_count = 0;
	while (s[i])
	{
		if ((s[i] != delimiter) && !word_found)
			word_found = 1;
		if ((s[i] == delimiter && word_found) || (!s[i + 1] && word_found))
		{
			words_count++;
			word_found = 0;
		}
		i++;
	}
	return (words_count);
}

/**
 * word_length - Calculate the length of a string
 *               until encountering a null terminator or a delimiter.
 * @s: the string to be analyzed.
 * @delimiter: the character used as the delimiter to identify words.
 * Return: the length of the word.
 */

static size_t	word_length(char const *s, char delimiter)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delimiter)
		i++;
	return (i);
}

/**
 * free_strings_array - Free the array of strings and each element in it.
 * @ptr: the pointer to the array of strings.
 * @s: the string to be analyzed.
 * @c: the delimiter character.
 * Return: NULL.
 */

static char	**free_strings_array(char **ptr)
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

/**
 * fill_strings_array - Fill the array of new strings resulting from the split.
 * @ptr: the pointer to the array of strings.
 * @s: the string to be analyzed.
 * @c: the delimiter character.
 * Return: Pointer to the array of strings.
 */

static char	**fill_strings_array(char **ptr, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = word_length(s + i, c);
		if (len > 0)
		{
			ptr[j] = ft_substr(s, i, len);
			if (!ptr[j])
				return (free_strings_array(ptr));
			j++;
			i += len;
		}
		else
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}

/**
 * ft_split - Allocates and returns an array of strings obtained 
 *            by splitting ’s’ using the character ’c’ as a delimiter.
 *            The array must end with a NULL pointer.
 * @s: the string to be split.
 * @c: the delimiter character.
 * Return: the array of new strings resulting from the split, 
 *         or NULL if the allocation fails.
 */

char	**ft_split(char *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	return (fill_strings_array(ptr, s, c));
}
