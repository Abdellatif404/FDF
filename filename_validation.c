/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:20:21 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/26 12:44:19 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putchar(char c)
{
	if (write(2, &c, 1) == -1)
		exit(FAILURE);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

static int	verify_extension(char *filename)
{
	int	i;

	i = 0;
	while (filename[i] != '.' && filename[i])
		i++;
	if (filename[i] == '.')
	{
		if (filename[i + 1] == 'f' && filename[i + 2] == 'd' \
		&& filename[i + 3] == 'f' && filename[i + 4] == '\0')
			return (SUCCESS);
	}
	return (FAILURE);
}

void	verify_filename(int ac, char **av)
{
	if (ac == 2)
	{
		if (verify_extension(av[1]) == FAILURE)
		{
			ft_putstr("ERROR: Wrong extension <filename>.fdf\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (ac == 1)
			ft_putstr("ERROR: You need to specify a filename\n");
		else if (ac > 2)
			ft_putstr("ERROR: Too many arguments\n");
		exit(EXIT_FAILURE);
	}
}
