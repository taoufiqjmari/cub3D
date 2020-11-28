/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:01:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/28 20:53:07 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	draw_rect2(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			mlx_pixel_put_img((x + i), (y + j), color);
			y++;
		}
		x++;
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
