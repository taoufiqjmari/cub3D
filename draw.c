/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:01:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/28 17:09:52 by tjmari           ###   ########.fr       */
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

void	draw_circle(int i, int j, int color)
{
	int	angle;
	int radius;
	int	x;
	int	y;

	angle = 0;
	radius = 0;
	g_init.radius = (color == 0x0040BF40) ? 8 : 32;
	while (radius < g_init.radius)
	{
		angle = 0;
		while (angle < 360)
		{
			x = i + (radius * cos(angle * M_PI / 180));
			y = j + (radius * sin(angle * M_PI / 180));
			mlx_pixel_put_img(x, y, color);
			angle++;
		}
		radius++;
	}
}
