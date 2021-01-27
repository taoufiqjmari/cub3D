/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:42:18 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 11:53:36 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sprite.h"

void	sprite(int tile_x, int tile_y)
{
	rect(tile_x, tile_y, 0x00BF4040);
}

void	salloc(void)
{
	if (!(g_sprites = malloc(sizeof(t_sprites) * g_sprite.count)))
		my_exit("sprite allocation failed");
}

void	put_data(int i, int j)
{
	static int	index = 0;

	i += TILE_SIZE / 2;
	j += TILE_SIZE / 2;
	g_sprites[index].x = j;
	g_sprites[index].y = i;
	index++;
}

void	sprite_data(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < g_elements.map_height)
	{
		j = 0;
		while (j < g_elements.map_width)
		{
			if (g_elements.map[i][j] == '2')
				put_data(i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	get_distance(void)
{
	int		i;

	i = 0;
	while (i < g_sprite.count)
	{
		g_sprites[i].distance = pythagore(g_ply.ply_x, g_ply.ply_y,
											g_sprites[i].x, g_sprites[i].y);
		g_sprites[i].angle = atan2(g_sprites[i].y - g_ply.ply_y,
									g_sprites[i].x - g_ply.ply_x);
		if ((g_ply.rotation_ang - FOV_ANG / 2) - g_sprites[i].angle > rad(180))
			g_sprites[i].angle += rad(360);
		if (g_sprites[i].angle - (g_ply.rotation_ang - FOV_ANG / 2) > rad(180))
			g_sprites[i].angle -= rad(360);
		i++;
	}
}
