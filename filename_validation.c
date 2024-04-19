/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:20:21 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 15:21:28 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			write(STDERR_FILENO, "ERROR: Wrong extension <filename>.fdf\n", 39);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (ac == 1)
			write(STDERR_FILENO, "ERROR: You need to specify a filename\n", 39);
		else if (ac > 2)
			write(STDERR_FILENO, "ERROR: Too many arguments\n", 27);
		exit(EXIT_FAILURE);
	}
}
