/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 09:57:09 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/20 17:01:55 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

void	map(int tile_x, int tile_y, int i, int j)
{
	if (g_elements.map[i][j] == '1')
		rect(MINIMAP_SCALE_FACTOR * tile_x,
				MINIMAP_SCALE_FACTOR * tile_y,
				0x00ADADAD);
	else if (g_elements.map[i][j] == '2')
		sprite(MINIMAP_SCALE_FACTOR * tile_x,
				MINIMAP_SCALE_FACTOR * tile_y);
	else if (g_elements.map[i][j] == 'W' || g_elements.map[i][j] == 'E'
				|| g_elements.map[i][j] == 'S' || g_elements.map[i][j] == 'N')
	{
		rect(MINIMAP_SCALE_FACTOR * tile_x,
			MINIMAP_SCALE_FACTOR * tile_y, 0x00F9F9F9);
	}
	else if (g_elements.map[i][j] == ' ')
		return ;
	else
		rect(MINIMAP_SCALE_FACTOR * tile_x,
				MINIMAP_SCALE_FACTOR * tile_y,
				0x00F9F9F9);
}

void	render_map(void)
{
	size_t	i;
	size_t	j;
	int		tile_x;
	int		tile_y;

	i = 0;
	while (i < g_elements.map_height)
	{
		j = 0;
		while (j < g_elements.map_width)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			map(tile_x, tile_y, i, j);
			j++;
		}
		i++;
	}
}
