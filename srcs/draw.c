/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:01:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/18 16:28:28 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	mlx_pixel_put_img(int x, int y, int color)
{
	char	*dst;

	dst = g_img.addr + (y * g_img.line_length +
							x * (g_img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	rect(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < TILE_SIZE)
	{
		y = 0;
		while (y < TILE_SIZE)
		{
			if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1)
				mlx_pixel_put_img((x + i), (y + j), 0x00ADADAD);
			else
				mlx_pixel_put_img((x + i), (y + j), color);
			y++;
		}
		x++;
	}
}

void	circle(int i, int j, int color)
{
	int	angle;
	int radius;
	int	x;
	int	y;

	angle = 0;
	radius = 0;
	g_ply.radius = (color == 0x000000FF)
					? TILE_SIZE / 16 : TILE_SIZE / 4;
	while (radius < g_ply.radius)
	{
		angle = 0;
		while (angle < 360)
		{
			x = i + (radius * cos(rad(angle)));
			y = j + (radius * sin(rad(angle)));
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

void	line(int x0, int y0, int x1, int y1)
{
	t_line	line;

	line.dx = x1 - x0;
	line.dy = y1 - y0;
	line.steps = abs(line.dx) > abs(line.dy) ? abs(line.dx) : abs(line.dy);
	line.x_inc = line.dx / (float)line.steps;
	line.y_inc = line.dy / (float)line.steps;
	line.x = x0;
	line.y = y0;
	line.i = 0;
	while (line.i <= line.steps)
	{
		mlx_pixel_put_img(line.x, line.y, 0x0000FF);
		line.x += line.x_inc;
		line.y += line.y_inc;
		line.i++;
	}
}
