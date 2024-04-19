/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:30:08 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 21:01:35 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initialize_scale(t_mlx *data)
{
	int	n;

	n = max(data->shape_height, data->shape_width);
	// if (n < 10)
	// 	return (50);
	// else if (n < 100)
	// 	return (20);
	// else if (n < 200)
	// 	return (10);
	return (data->steps);
}

static void	clear_image(t_img *img)
{
	int	*image;
	int	i;

	image = (int *)(img->addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		image[i] = 0;
		i++;
	}
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pixel = img->addr + (y * img->size_line) + (x * img->bpp / 8);
		*(int *)pixel = color;
	}
}

static void	connect_points(t_img *img, t_line_params *params, t_matrix *column)
{
	if (column->right)
	{
		column->right->x = column->x + params->scale;
		column->right->y = column->y;
		if ((column->right->x >= 0 && column->x <= WIN_WIDTH) \
		&& (column->right->y >= 0 && column->y <= WIN_HEIGHT))
			bresenham(img, column, column->right, params);
	}
	if (column->down)
	{
		column->down->x = column->x;
		column->down->y = column->y + params->scale;
		if ((column->down->x >= 0 && column->x <= WIN_WIDTH) \
		&& (column->down->y >= 0 && column->y <= WIN_HEIGHT))
			bresenham(img, column, column->down, params);
	}
}

int	init_params_and_pixel(t_mlx *data, t_line_params **prms, t_pixel_info **pxl)
{
	*prms = malloc(sizeof(t_line_params));
	if (!*prms)
		return (FAILURE);
	*pxl = malloc(sizeof(t_pixel_info));
	if (!*pxl)
	{
		free(*prms);
		return (FAILURE);
	}
	(*prms)->scale = initialize_scale(data);
	(*prms)->pixel = *pxl;
	return (SUCCESS);
}

int	draw_map(t_mlx *mlx, t_matrix **head)
{
	t_matrix		*row;
	t_matrix		*column;
	t_line_params	*params;
	t_pixel_info	*pixel;

	row = *head;
	column = *head;
	if (init_params_and_pixel(mlx, &params, &pixel) == FAILURE)
		return (FAILURE);
	clear_image(&mlx->img);
	while (row)
	{
		column = row;
		while (column)
		{
			connect_points(&mlx->img, params, column);
			column = column->right;
		}
		row = row->down;
	}
	free(params);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mlx_img, 0, 0);
	return (SUCCESS);
}
