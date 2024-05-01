/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:49:59 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/27 13:34:39 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
