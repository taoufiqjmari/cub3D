/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:01:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 17:46:12 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	mlx_pixel_put_img(int x, int y, int color)
{
	char	*dst;

	dst = g_init.addr + (y * g_init.line_length +
							x * (g_init.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rect(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < g_init.tile_size)
	{
		y = 0;
		while (y < g_init.tile_size)
		{
			mlx_pixel_put_img((x + i), (y + j), color);
			y++;
		}
		x++;
	}
}

void	draw_circle(int i, int j, int color)
{
	int	angle;
	int radius;
	int	x;
	int	y;

	angle = 0;
	radius = 0;
	g_init.radius = (color == 0x000000FF) ? g_init.tile_size / 16 : g_init.tile_size / 4;
	while (radius < g_init.radius)
	{
		angle = 0;
		while (angle < 360)
		{
			x = i + (radius * cos(deg_rad(angle)));
			y = j + (radius * sin(deg_rad(angle)));
			mlx_pixel_put_img(x, y, color);
			angle++;
		}
		radius++;
	}
}

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void	draw_line(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float x_inc = dx / (float)steps;
	float y_inc = dy / (float)steps;

	float x = x0;
	float y = y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put_img(x, y, 0x0000FF);
		x += x_inc;
		y += y_inc;
	}
}
