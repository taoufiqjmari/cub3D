/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:34:39 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/23 18:27:22 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
	line(MINIMAP_SCALE_FACTOR * g_ply.ply_x + cos(g_ply.rotation_ang) * TILE_SIZE / 2,
			MINIMAP_SCALE_FACTOR * g_ply.ply_y + sin(g_ply.rotation_ang) * TILE_SIZE / 2,
			0x00000000);
}
