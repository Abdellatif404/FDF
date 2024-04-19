/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:57:02 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 20:47:55 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	count_steps(int color1, int color2, int scale)
{
	float	steps;

	steps = 0;
	if (color1 > color2)
	{
		steps = (float)(color1 - color2) / scale;
	}
	else if (color1 < color2)
	{
		steps = (float)(color2 - color1) / scale;
	}
	return (steps);
}

static void	init_params(t_line_params *prms, t_matrix *pt1, t_matrix *pt2)
{
	prms->pixel->r = pt1->red;
	prms->pixel->g = pt1->green;
	prms->pixel->b = pt1->blue;
	prms->pixel->r_steps = count_steps(pt1->red, pt2->red, prms->scale);
	prms->pixel->g_steps = count_steps(pt1->green, pt2->green, prms->scale);
	prms->pixel->b_steps = count_steps(pt1->blue, pt2->blue, prms->scale);
	prms->pixel->r_remainder = 0;
	prms->pixel->g_remainder = 0;
	prms->pixel->b_remainder = 0;
	prms->decision = 0;
	prms->slope = 0;
	prms->dx = pt2->x - pt1->x;
	prms->dy = pt2->y - pt1->y;
	if (prms->dx != 0)
		prms->slope = prms->dy / prms->dx;
	if (prms->dx && prms->slope <= 1)
		prms->decision = 2 * prms->dy - prms->dx;
	else if (prms->dx && prms->slope > 1)
		prms->decision = 2 * prms->dx - prms->dy;
}

static void	move_by_decision(int decision, int *x, int *y, int mode)
{
	if (mode == 0)
	{
		if (decision >= 0)
		{
			(*x)++;
			(*y)++;
		}
		else if (decision < 0)
			(*x)++;
	}
	else if (mode == 1)
	{
		if (decision >= 0)
		{
			(*x)++;
			(*y)++;
		}
		else if (decision < 0)
			(*y)++;
	}
}

int	divide_and_round(float *remainder, float steps)
{
	int	i;

	i = (int)(steps + *remainder);
	*remainder = (steps + *remainder) - (int)(steps + *remainder);
	return (i);
}

void	update_coordinates(t_line_params *prms, int *x, int *y)
{
	if (prms->dx == 0)
		(*y)++;
	else if (prms->dy == 0)
		(*x)++;
	else if (prms->slope <= 1)
	{
		move_by_decision(prms->decision, x, y, 0);
		prms->decision = prms->decision + 2 * prms->dy - 2 * prms->dx;
	}
	else if (prms->slope > 1)
	{
		move_by_decision(prms->decision, x, y, 1);
		prms->decision = prms->decision + 2 * prms->dx - 2 * prms->dy;
	}
}

void	update_color(int *color1, int color2, float *remainder, float steps)
{
	if (*color1 < color2 - *remainder)
		*color1 += divide_and_round(remainder, steps);
	else if (*color1 > color2 + *remainder)
		*color1 -= divide_and_round(remainder, steps);
}

void	update_pixel(t_pixel_info *pixel, t_matrix *point)
{
	update_color(&pixel->r, point->red, &pixel->r_remainder, pixel->r_steps);
	update_color(&pixel->g, point->green, &pixel->g_remainder, pixel->g_steps);
	update_color(&pixel->b, point->blue, &pixel->b_remainder, pixel->b_steps);
}

void	bresenham(t_img *img, t_matrix *pt1, t_matrix *pt2, t_line_params *prms)
{
	int	x;
	int	y;
	int	color;

	x = pt1->x;
	y = pt1->y;
	init_params(prms, pt1, pt2);
	while (x <= pt2->x && y <= pt2->y)
	{
		color = (prms->pixel->r << 16) | (prms->pixel->g << 8) | prms->pixel->b;
		img_pixel_put(img, x, y, color);
		update_pixel(prms->pixel, pt2);
		update_coordinates(prms, &x, &y);
	}
}
