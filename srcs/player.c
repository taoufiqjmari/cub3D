/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:34:39 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/27 12:45:04 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	define_ply(int tile_x, int tile_y)
{
	rect(MINIMAP_SCALE_FACTOR * tile_x,
			MINIMAP_SCALE_FACTOR * tile_y,
			0x00F9F9F9);
	if (!g_ply.player_defined)
	{
		g_ply.ply_x = tile_x + TILE_SIZE / 2;
		g_ply.ply_y = tile_y + TILE_SIZE / 2;
		if (g_ply.ply_init_dir == 'W')
			g_ply.rotation_ang = rad(180);
		else if (g_ply.ply_init_dir == 'E')
			g_ply.rotation_ang = rad(0);
		else if (g_ply.ply_init_dir == 'S')
			g_ply.rotation_ang = rad(90);
		else if (g_ply.ply_init_dir == 'N')
			g_ply.rotation_ang = rad(270);
		g_ply.player_defined = 1;
	}
}

_Bool	map_has_wall_at(float new_x, float new_y)
{
	int	map_index_x;
	int	map_index_y;
	int	angle;
	int	x;
	int	y;

	angle = 0;
	while (angle < 360)
	{
		x = new_x + cos(rad(angle)) * 5;
		y = new_y + sin(rad(angle)) * 5;
		map_index_x = x / TILE_SIZE;
		map_index_y = y / TILE_SIZE;
		if (g_map[map_index_y][map_index_x] == ' ' ||
			g_map[map_index_y][map_index_x] == '1' ||
			g_map[map_index_y][map_index_x] == '2')
			return (1);
		angle += 90;
	}
	return (0);
}

void	update_player(void)
{
	float	move_step;
	float	new_x;
	float	new_y;

	g_ply.rotation_ang += g_ply.turn_direction * g_ply.rotation_speed;
	g_ply.rotation_ang = normalize_ang(g_ply.rotation_ang);
	move_step = g_ply.walk_direction * g_ply.move_speed;
	if (g_ply.straight)
	{
		new_x = g_ply.ply_x + cos(g_ply.rotation_ang) * move_step;
		new_y = g_ply.ply_y + sin(g_ply.rotation_ang) * move_step;
	}
	else
	{
		new_x = g_ply.ply_x + cos(g_ply.rotation_ang + rad(90)) * move_step;
		new_y = g_ply.ply_y + sin(g_ply.rotation_ang + rad(90)) * move_step;
	}
	if (!map_has_wall_at(new_x, new_y))
	{
		g_ply.ply_x = new_x;
		g_ply.ply_y = new_y;
	}
	g_ply.turn_direction = 0;
	g_ply.walk_direction = 0;
}

void	render_player(void)
{
	circle(MINIMAP_SCALE_FACTOR * g_ply.ply_x,
			MINIMAP_SCALE_FACTOR * g_ply.ply_y,
			0x00000000);
	line(MINIMAP_SCALE_FACTOR * g_ply.ply_x + cos(g_ply.rotation_ang)
			* TILE_SIZE / 2,
			MINIMAP_SCALE_FACTOR * g_ply.ply_y + sin(g_ply.rotation_ang)
			* TILE_SIZE / 2,
			0x00000000);
}
