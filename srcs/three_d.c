/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:37:50 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/25 09:59:29 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	change_color_intensity(int *color, float factor)
{
	int a = (*color & 0xFF000000);
	int r = (*color & 0x00FF0000) * factor;
	int g = (*color & 0x0000FF00) * factor;
	int b = (*color & 0x000000FF) * factor;

	*color = a | (r & 0x00FF0000) | (g & 0x0000FF00) | (b & 0x000000FF);
}

void	ceiling(int i, int wall_top_pixel)
{
	int y;

	y = 0;
	while (y < wall_top_pixel)
	{
		mlx_pixel_put_img(i, y, 0x0000CEE1);
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

	if(g_rays[i].is_ray_up && !g_rays[i].was_hit_ver)
		index = 0;
	else if(g_rays[i].is_ray_down && !g_rays[i].was_hit_ver)
		index = 1;
	else if(g_rays[i].is_ray_right && g_rays[i].was_hit_ver)
		index = 2;
	else if(g_rays[i].is_ray_left && g_rays[i].was_hit_ver)
		index = 3;

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
		texel_color = g_texture.texel[index][(g_texture.height[index] * texture_offset_y)
						+ texture_offset_x];
		if (g_rays[i].was_hit_ver)
			change_color_intensity(&texel_color, 1.0);
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
		mlx_pixel_put_img(i, y, 0x0000E10F);
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

	g_texture.file[0] = "./textures/bluestone.xpm";
	g_texture.file[1] = "./textures/wall_4.xpm";
	g_texture.file[2] = "./textures/wood.xpm";
	g_texture.file[3] = "./textures/wall_3.xpm";
	if(!(g_texture.txt[0] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[0],
		&g_texture.width[0], &g_texture.height[0])))
		printf("mlx_xpm_file_to_image() failed\n");
	if(!(g_texture.txt[1] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[1],
		&g_texture.width[1], &g_texture.height[1])))
		printf("mlx_xpm_file_to_image() failed\n");
	if(!(g_texture.txt[2] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[2],
		&g_texture.width[2], &g_texture.height[2])))
		printf("mlx_xpm_file_to_image() failed\n");
	if(!(g_texture.txt[3] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[3],
		&g_texture.width[3], &g_texture.height[3])))
		printf("mlx_xpm_file_to_image() failed\n");

	g_texture.texel[0] = (int *)mlx_get_data_addr(g_texture.txt[0],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[1] = (int *)mlx_get_data_addr(g_texture.txt[1],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[2] = (int *)mlx_get_data_addr(g_texture.txt[2],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[3] = (int *)mlx_get_data_addr(g_texture.txt[3],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);

	i = 0;
	while (i < NUM_RAYS)
	{
		perp_distance = g_rays[i].distance * cos(g_rays[i].ray_ang
						- g_ply.rotation_ang);
		distance_proj_plane = (WIN_WIDTH / 2) / tan(FOV_ANG / 1.5);
		wall_strip_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
		wall_top_pixel = (WIN_HEIGHT / 2) - (wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;
		wall_bottom_pixel = (WIN_HEIGHT / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > WIN_HEIGHT
							? WIN_HEIGHT : wall_bottom_pixel;
		ceiling(i, wall_top_pixel);
		grounding(i, wall_top_pixel, wall_bottom_pixel, wall_strip_height);
		flooring(i, wall_bottom_pixel);
		i++;
	}
}
