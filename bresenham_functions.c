/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:57:02 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/28 23:03:07 by aelbouz          ###   ########.fr       */
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
	prms->x_direction = 1;
	prms->y_direction = 1;
	if (pt1->x > pt2->x)
		prms->x_direction = -1;
	if (pt1->y > pt2->y)
		prms->y_direction = -1;
	prms->pixel->r = pt1->red;
	prms->pixel->g = pt1->green;
	prms->pixel->b = pt1->blue;
	prms->pixel->r_steps = count_steps(pt1->red, pt2->red, prms->scale + (prms->scale / 3));
	prms->pixel->g_steps = count_steps(pt1->green, pt2->green, prms->scale + (prms->scale / 3));
	prms->pixel->b_steps = count_steps(pt1->blue, pt2->blue, prms->scale + (prms->scale / 3));
	prms->pixel->r_remainder = 0;
	prms->pixel->g_remainder = 0;
	prms->pixel->b_remainder = 0;
	prms->dx = abs(pt1->x - pt2->x);
	prms->dy = abs(pt1->y - pt2->y);
	if (prms->dx && prms->dy)
	{
		prms->slope = prms->dy / prms->dx;
		if (prms->slope < 1)
			prms->decision = (2 * prms->dy) - prms->dx;
		else
			prms->decision = (2 * prms->dx) - prms->dy;
	}
}

static void	move_by_decision(t_line_params *prms, int *x, int *y, int mode)
{
	if (prms->decision < 0 && mode == 0)
		(*x) += prms->x_direction;
	else if (prms->decision < 0 && mode == 1)
		(*y) += prms->y_direction;
	else
	{
		(*x) += prms->x_direction;
		(*y) += prms->y_direction;
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
		(*y) += prms->y_direction;
	else if (prms->dy == 0)
		(*x) += prms->x_direction;
	else if (prms->slope < 1)
	{
		move_by_decision(prms, x, y, 0);
		if (prms->decision < 0)
			prms->decision = prms->decision + (2 * prms->dy);
		else
			prms->decision = prms->decision + (2 * prms->dy) - (2 * prms->dx);
	}
	else
	{
		move_by_decision(prms, x, y, 1);
		if (prms->decision < 0)
			prms->decision = prms->decision + (2 * prms->dx);
		else
			prms->decision = prms->decision + (2 * prms->dx) - (2 * prms->dy);
	}
}

void	update_color(int *color1, int color2, float *remainder, float steps)
{
	if (*color1 < color2 - *remainder)
		*color1 += divide_and_round(remainder, steps);
	else if (*color1 > color2 + *remainder)
		*color1 -= divide_and_round(remainder, steps);
	if (*color1 > 255)
		*color1 = 255;
	else if (*color1 < 0)
		*color1 = 0;
}

void	update_pixel(t_pixel_info *pixel, t_matrix *point)
{
	update_color(&pixel->r, point->red, &pixel->r_remainder, pixel->r_steps);
	update_color(&pixel->g, point->green, &pixel->g_remainder, pixel->g_steps);
	update_color(&pixel->b, point->blue, &pixel->b_remainder, pixel->b_steps);
}

int	until(int xi, int xf, int yi, int yf, int mode)
{
	if (mode == 1)
		return (xi <= xf && yi <= yf);
	else if (mode == 2)
		return (xi <= xf && yi >= yf);
	else if (mode == 3)
		return (xi >= xf && yi <= yf);
	else if (mode == 4)
		return (xi >= xf && yi >= yf);
	return (0);
}

void	bresenham(t_image *img, t_matrix *pt1, t_matrix *pt2, t_line_params *prms)
{
	int	x;
	int	y;
	int	color;
	int	mode;

	x = pt1->x;
	y = pt1->y;
	init_params(prms, pt1, pt2);
	if (x <= pt2->x && y <= pt2->y)
		mode = 1;
	else if (x <= pt2->x && y >= pt2->y)
		mode = 2;
	else if (x >= pt2->x && y <= pt2->y)
		mode = 3;
	else if (x >= pt2->x && y >= pt2->y)
		mode = 4;
	while (until(x, pt2->x, y, pt2->y, mode))
	{
		color = (prms->pixel->r << 16) | (prms->pixel->g << 8) | prms->pixel->b;
		img_pixel_put(img, x, y, color);
		update_pixel(prms->pixel, pt2);
		update_coordinates(prms, &x, &y);
	}
}
