/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 09:57:09 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/28 15:59:35 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map(int tile_x, int tile_y, int i, int j)
{
	if (g_reading.map[i][j] == '1')
		rect(MINIMAP_SCALE_FACTOR * tile_x,
				MINIMAP_SCALE_FACTOR * tile_y,
				0x00ADADAD);
	else if (g_reading.map[i][j] == '2')
		sprite(MINIMAP_SCALE_FACTOR * tile_x,
				MINIMAP_SCALE_FACTOR * tile_y);
	else if (g_reading.map[i][j] == 'W' || g_reading.map[i][j] == 'E'
				|| g_reading.map[i][j] == 'S' || g_reading.map[i][j] == 'N')
	{
		g_ply.ply_init_dir = g_reading.map[i][j];
		define_ply(tile_x, tile_y);
	}
	else if (g_reading.map[i][j] == ' ')
		return ;
	else
		rect(MINIMAP_SCALE_FACTOR * tile_x,
				MINIMAP_SCALE_FACTOR * tile_y,
				0x00F9F9F9);
}

void	render_map(void)
{
	int	i;
	int	j;
	int	tile_x;
	int	tile_y;

	i = 0;
	while (i < g_reading.map_height)
	{
		j = 0;
		while (j < g_reading.map_longest_line)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			map(tile_x, tile_y, i, j);
			j++;
		}
		i++;
	}
}
