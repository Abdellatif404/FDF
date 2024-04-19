/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:21:20 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 21:10:30 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line/get_next_line.h"
#include "errno.h"

void	print_matrix(t_matrix **head)
{
	t_matrix	*row;
	t_matrix	*column;

	row = *head;
	column = *head;
	while (row)
	{
		column = row;
		while (column)
		{
			// printf("(%d, %d, %d) ", column->x_idx, column->y_idx, column->z);
			// printf("(%d, %d, %d) ", column->red, column->green, column->blue);
			// printf("(%d) ", column->z);
			column = column->right;
		}
		// printf("\n");
		row = row->down;
	}
}

// int	count_file_length(char *filename)
// {
// 	int	fd;
// 	int	rd;
// 	char *buff;
// 	int	len;

// 	fd = open(filename, O_RDONLY);
// 	rd = 1;
// 	len = 0;
// 	buff = malloc(10000 * sizeof(char));
// 	buff[0] = 0;
// 	while (rd != 0)
// 	{
// 		rd = read(fd, buff, 9999);
// 		buff[rd] = 0;
// 		len += ft_strlen(buff);
// 	}
// 	return (len);
// }


int	move_map(int keycode, t_mlx *data)
{
	if (keycode == 126)
	{
		printf("UP arrow key pressed\n");
		(**(data->head)).y -= 10;
		draw_map(data, data->head);
	}
	else if (keycode == 125)
	{
		printf("DOWN arrow key pressed\n");
		(**(data->head)).y += 10;
		draw_map(data, data->head);
	}
	else if (keycode == 123)
	{
		printf("LEFT arrow key pressed\n");
		(**(data->head)).x -= 10;
		draw_map(data, data->head);
	}
	else if (keycode == 124)
	{
		printf("RIGHT arrow key pressed\n");
		(**(data->head)).x += 10;
		draw_map(data, data->head);
	}
	else if (keycode == 53)
	{
		// mlx_destroy_image(test->ml.mlx_ptr, &test->ml.img.addr);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data-> mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	else
		printf("Unknown key pressed %d\n", keycode);
	return (0);
}

static int	centering(int dimension, int file_dim, int scale)
{
	return ((dimension / 2) - ((file_dim - 1) * scale / 2));
}

int	zoom(int keycode, int x, int y, t_mlx *data)
{
	printf("mouse position %d, %d\n", x, y);
	if (keycode == 5)
	{
		data->steps += 1;
		(*(data->head))->x = centering(WIN_WIDTH, data->shape_width, data->steps);
		(*(data->head))->y = centering(WIN_HEIGHT, data->shape_height, data->steps);
		draw_map(data, data->head);
	}
	else if (keycode == 4)
	{
		if (data->steps > 1)
			data->steps -= 1;
		(*(data->head))->x = centering(WIN_WIDTH, data->shape_width, data->steps);
		(*(data->head))->y = centering(WIN_HEIGHT, data->shape_height, data->steps);
		draw_map(data, data->head);
	}
	// else if (keycode == 3)
	// {
	// 	(*(data->head))->x = centering(WIN_WIDTH, data->shape_width, data->steps);
	// 	(*(data->head))->y = centering(WIN_HEIGHT, data->shape_height, data->steps);
	// 	draw_map(data, data->head);
	// }
	// else
	// 	printf("Unknown key pressed %d\n", keycode);
	return (0);
}

void	init_mlx_data(t_mlx *mlx, t_matrix **head)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(EXIT_FAILURE);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (mlx->win_ptr == NULL)
		exit(EXIT_FAILURE);
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr , WIN_WIDTH, WIN_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, &mlx->img.bpp, \
	&mlx->img.size_line, &mlx->img.endian);
	mlx->head = head;
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_matrix	**head;

	verify_filename(ac, av);
	get_file_dimensions(av[1], &mlx);
	printf("FILE DIMENSIONS : height= %d, width= %d\n", mlx.shape_height, mlx.shape_width);
	head = create_matrix(&mlx);
	if (!head)
	{
		perror("Failed to create the matrix");
		exit(EXIT_FAILURE);
	}
	init_mlx_data(&mlx, head);
	if (parse_map(av[1], head) == FAILURE)
	{
		// free_matrix();
		perror("Failed to parse the map");
		exit(EXIT_FAILURE);
	}
	if (draw_map(&mlx, head) == FAILURE)
	{
		// free_matrix();
		perror("Failed to draw the map");
		exit(EXIT_FAILURE);
	}
	print_matrix(head);
	// BELOW IS A TEST TO MOVE THE MAP
	mlx_key_hook(mlx.win_ptr, move_map, &mlx);
	mlx_mouse_hook(mlx.win_ptr, zoom, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_image(mlx.mlx_ptr, mlx.img.mlx_img);
	return (0);
}
