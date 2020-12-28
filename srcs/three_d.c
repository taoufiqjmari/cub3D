/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:37:50 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/28 09:28:39 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	what_index(int i, int *index)
{
	if (g_rays[i].is_ray_up && !g_rays[i].was_hit_ver)
		*index = 0;
	else if (g_rays[i].is_ray_down && !g_rays[i].was_hit_ver)
		*index = 1;
	else if (g_rays[i].is_ray_right && g_rays[i].was_hit_ver)
		*index = 2;
	else if (g_rays[i].is_ray_left && g_rays[i].was_hit_ver)
		*index = 3;
}

void	ceiling(int i, int wall_top_pixel)
{
	int y;

	y = 0;
	while (y < wall_top_pixel)
	{
		mlx_pixel_put_img(i, y, g_texture.ceiling_color);
		y++;
	}
}

void	grounding(int i, int wall_t_p, int wall_b_p, int wall_strip_h)
{
	int		texture_offset_x;
	int		y;
	int		distance_from_top;
	int		texture_offset_y;
	int		texel_color;
	int		index;

	what_index(i, &index);
	if (g_rays[i].was_hit_ver)
		texture_offset_x = (int)g_rays[i].wall_hit_y % g_texture.height[index];
	else
		texture_offset_x = (int)g_rays[i].wall_hit_x % g_texture.width[index];
	y = wall_t_p;
	while (y < wall_b_p)
	{
		distance_from_top = y + (wall_strip_h / 2) - (WIN_HEIGHT / 2);
		texture_offset_y = distance_from_top *
							((float)g_texture.height[index] / wall_strip_h);
		texel_color = g_texture.texel[index][(g_texture.height[index]
			* texture_offset_y) + texture_offset_x];
		mlx_pixel_put_img(i, y, texel_color);
		y++;
	}
}

void	flooring(int i, int wall_bottom_pixel)
{
	int y;

	y = wall_bottom_pixel;
	while (y < WIN_HEIGHT)
	{
		mlx_pixel_put_img(i, y, g_texture.floor_color);
		y++;
	}
}

void	render_3d(void)
{
	int		i;
	float	perp_distance;
	float	distance_proj_plane;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = g_rays[i].distance * cos(g_rays[i].ray_ang
						- g_ply.rotation_ang);
		distance_proj_plane = (g_mlx.win_width / 2) / tan(FOV_ANG / 1.5);
		wall_strip_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
		wall_top_pixel = (g_mlx.win_height / 2) - (wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = (g_mlx.win_height / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > g_mlx.win_height
							? g_mlx.win_height : wall_bottom_pixel;
		ceiling(i, wall_top_pixel);
		grounding(i, wall_top_pixel, wall_bottom_pixel, wall_strip_height);
		flooring(i, wall_bottom_pixel);
		i++;
	}
}
