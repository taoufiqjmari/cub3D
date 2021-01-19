/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:37:50 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/18 09:53:58 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/three.h"

void	ceiling(int x, int wall_top_pixel)
{
	int y;

	y = 0;
	while (y < wall_top_pixel)
	{
		mlx_pixel_put_img(x, y, g_fc.ceiling);
		y++;
	}
}

void	grounding(int x, int wall_t_p, int wall_b_p, int wall_strip_h)
{
	int		y;
	int		distance_from_top;
	int		texel_color;
	int		index;

	what_index(x, &index);
	if (g_rays[x].was_hit_ver)
		g_texture.offset_x = (int)g_rays[x].wall_hit_y % g_texture.h[index];
	else
		g_texture.offset_x = (int)g_rays[x].wall_hit_x % g_texture.w[index];
	y = wall_t_p;
	while (y < wall_b_p)
	{
		distance_from_top = y + (wall_strip_h / 2) - (g_mlx.win_height / 2);
		g_texture.offset_y = distance_from_top *
							((float)g_texture.h[index] / wall_strip_h);
		texel_color = g_texture.texel[index][(g_texture.h[index]
			* g_texture.offset_y) + g_texture.offset_x];
		mlx_pixel_put_img(x, y, texel_color);
		y++;
	}
}

void	flooring(int x, int wall_bottom_pixel)
{
	int y;

	y = wall_bottom_pixel;
	while (y < g_mlx.win_height)
	{
		mlx_pixel_put_img(x, y, g_fc.floor);
		y++;
	}
}

void	render_3d(void)
{
	int		x;
	float	perp_distance;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	x = 0;
	while (x < g_mlx.win_width)
	{
		perp_distance = g_rays[x].distance * cos(g_rays[x].ray_ang
						- g_ply.rotation_ang);
		perp_distance = perp_distance == 0 ? 1 : perp_distance;
		wall_strip_height = (TILE_SIZE / perp_distance) * g_distance_proj_plane;
		wall_top_pixel = (g_mlx.win_height / 2) - (wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = (g_mlx.win_height / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > g_mlx.win_height
							? g_mlx.win_height : wall_bottom_pixel;
		ceiling(x, wall_top_pixel);
		grounding(x, wall_top_pixel, wall_bottom_pixel, wall_strip_height);
		flooring(x, wall_bottom_pixel);
		x++;
	}
}
