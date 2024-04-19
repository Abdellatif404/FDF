/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:22:09 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/18 15:03:49 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ctoi(char c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	else if (c >= 65 && c <= 70)
		return (c - 55);
	else if (c >= 97 && c <= 102)
		return (c - 87);
	return (-1);
}

int	ft_htoi(char *s)
{
	int			i;
	long long	res;
	short		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ctoi(s[i]) != -1 && ctoi(s[i]) < 16 && s[i])
	{
		if (i >= 2)
			break ;
		res = res * 16 + ctoi(s[i]);
		i++;
	}
	return (res * sign);
}
