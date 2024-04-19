/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:16:29 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/03/16 14:27:37 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}

static int	ft_issign(int c)
{
	return (c == 43 || c == 45);
}

static int	ft_isspace(int c)
{
	return (c == 32);
}

int	ft_atoi(char *s)
{
	int			i;
	long long	res;
	short		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (ft_issign(s[i]))
	{
		sign = -(s[i] - 44);
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res * sign);
}