/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:34:39 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/02 10:45:53 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_player(void)
{
	draw_circle(g_init.ply_x,
				g_init.ply_y,
				0x000000FF);
	draw_line(g_init.ply_x,
				g_init.ply_y,
				g_init.ply_x + cos(g_init.rotation_angle) * g_init.tile_size / 2,
				g_init.ply_y + sin(g_init.rotation_angle) * g_init.tile_size / 2
			);
}

void	update_player(void)
{
	float	move_step;
	float	new_ply_x;
	float	new_ply_y;

	g_init.rotation_angle += g_init.turn_direction * g_init.rotation_speed;
	if (g_init.rotation_angle < deg_rad(0))
		g_init.rotation_angle = deg_rad(360);
	else if (g_init.rotation_angle > deg_rad(360))
		g_init.rotation_angle = deg_rad(0);

	move_step = g_init.walk_direction * g_init.move_speed;
	if (g_init.straight)
	{
		new_ply_x = g_init.ply_x + cos(g_init.rotation_angle) * move_step;
		new_ply_y = g_init.ply_y + sin(g_init.rotation_angle) * move_step;
	}
	else
	{
		new_ply_x = g_init.ply_x + cos(g_init.rotation_angle + deg_rad(90)) * move_step;
		new_ply_y = g_init.ply_y + sin(g_init.rotation_angle + deg_rad(90)) * move_step;
	}
	if (!map_has_wall_at(new_ply_x, new_ply_y))
	{
		g_init.ply_x = new_ply_x;
		g_init.ply_y = new_ply_y;
	}

	g_init.turn_direction = 0;
	g_init.walk_direction = 0;
}
