/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:01:20 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/29 12:01:45 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(void)
{
	int i;
	int j;
	int tile_x;
	int tile_y;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * g_init.tile_size;
			tile_y = i * g_init.tile_size;
			if (g_map[i][j] == '1')
				draw_rect(tile_x, tile_y, 0x00ADADAD); //grey borders
			else if (g_map[i][j] == '2')
			{
				draw_rect(tile_x, tile_y, 0x00F9F9F9); //white background
				draw_circle(tile_x + g_init.tile_size / 2,
							tile_y + g_init.tile_size / 2,
							0x00BF4040); //red sprite
			}
			else if (g_map[i][j] == 'N' || g_map[i][j] == 'R'
						|| g_map[i][j] == 'S' || g_map[i][j] == 'W')
			{
				draw_rect(tile_x, tile_y, 0x00F9F9F9); //white background
				g_init.ply_x = tile_x;
				g_init.ply_y = tile_y;
			}
			else if (g_map[i][j] == ' ')
			{
				j++;
				continue;
			}
			else
				draw_rect(tile_x, tile_y, 0x00F9F9F9); //while board
			j++;
		}
		i++;
	}
}

void	render_player(void)
{
	draw_circle(g_init.ply_x + g_init.tile_size / 2,
				g_init.ply_y + g_init.tile_size / 2,
				0x000000FF);
	draw_line(g_init.ply_x + g_init.tile_size / 2,
				g_init.ply_y + g_init.tile_size / 2,
				g_init.ply_x + cos(g_init.rotation_angle) * g_init.tile_size / 2 + g_init.tile_size / 2,
				g_init.ply_y + sin(g_init.rotation_angle) * g_init.tile_size / 2 + g_init.tile_size / 2
			);
}
