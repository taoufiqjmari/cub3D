/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:34:39 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 20:24:27 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	define_ply(int tile_x, int tile_y)
{
	rect(tile_x, tile_y, 0x00F9F9F9);
	if (!g_init.player_defined)
	{
		g_init.ply_x = tile_x + g_init.tile_size / 2;
		g_init.ply_y = tile_y + g_init.tile_size / 2;
		if (g_init.ply_init_dir == 'W')
			g_init.rotation_ang = rad(180);
		else if (g_init.ply_init_dir == 'E')
			g_init.rotation_ang = rad(0);
		else if (g_init.ply_init_dir == 'S')
			g_init.rotation_ang = rad(90);
		else if (g_init.ply_init_dir == 'N')
			g_init.rotation_ang = rad(270);
		g_init.player_defined = 1;
	}
}

void	update_player(void)
{
	float	move_step;
	float	new_x;
	float	new_y;

	g_init.rotation_ang += g_init.turn_direction * g_init.rotation_speed;
	normalize_degree();
	move_step = g_init.walk_direction * g_init.move_speed;
	if (g_init.straight)
	{
		new_x = g_init.ply_x + cos(g_init.rotation_ang) * move_step;
		new_y = g_init.ply_y + sin(g_init.rotation_ang) * move_step;
	}
	else
	{
		new_x = g_init.ply_x + cos(g_init.rotation_ang + rad(90)) * move_step;
		new_y = g_init.ply_y + sin(g_init.rotation_ang + rad(90)) * move_step;
	}
	if (!map_has_wall_at(new_x, new_y))
	{
		g_init.ply_x = new_x;
		g_init.ply_y = new_y;
	}
	g_init.turn_direction = 0;
	g_init.walk_direction = 0;
}

void	normalize_degree(void)
{
	if (g_init.rotation_ang < rad(0))
		g_init.rotation_ang = rad(360);
	else if (g_init.rotation_ang > rad(360))
		g_init.rotation_ang = rad(0);
}

void	render_player(void)
{
	circle(g_init.ply_x,
				g_init.ply_y,
				0x000000FF);
	line(g_init.ply_x,
				g_init.ply_y,
				g_init.ply_x + cos(g_init.rotation_ang) * g_init.tile_size / 2,
				g_init.ply_y + sin(g_init.rotation_ang) * g_init.tile_size / 2);
}
