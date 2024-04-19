/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:16:38 by ael-bouz          #+#    #+#             */
/*   Updated: 2023/11/11 17:16:38 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * ft_bzero - fill memory with a zero-valued bytes (bytes containing \0).
 * @s: a pointer to the block of memory to fill.
 * @n: the number of bytes to be set to zero.
 * Return: none.
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*src;

	src = s;
	while (n > 0)
	{
		*src = 0;
		if (n > 1)
			src++;
		n--;
	}
}
