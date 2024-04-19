/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:17:50 by ael-bouz          #+#    #+#             */
/*   Updated: 2023/11/11 21:17:50 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * ft_calloc - Allocates the requested memory and sets it to zero.
 * @count: the number of elements to be allocated.
 * @size:  the size of elements.
 * Return: a pointer to the allocated memory, or NULL if the request fails.
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
