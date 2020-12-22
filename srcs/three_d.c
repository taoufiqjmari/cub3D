/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:37:50 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/22 18:07:58 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		wall_texture[4096];

void	render_3d(void)
{
	int i;

	i = 0;
	while (i < NUM_RAYS)
	{
		float	perp_distance = g_rays[i].distance * cos(g_rays[i].ray_ang - g_ply.rotation_ang);
		float	distance_proj_plane = (IMG_WIDTH / 2) / tan(FOV_ANG / 2);
		float	projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;

		int		wall_strip_height = (int)projected_wall_height;

		int		wall_top_pixel = (IMG_HEIGHT / 2) - (wall_strip_height / 2);
		wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;

		int		wall_bottom_pixel = (IMG_HEIGHT / 2) + (wall_strip_height / 2);
		wall_bottom_pixel = wall_bottom_pixel > IMG_HEIGHT ? IMG_HEIGHT : wall_bottom_pixel;

		for(int y = 0; y < wall_top_pixel; y++)
			mlx_pixel_put_img(i, y, 0x00333333);



		for(int x = 0; x < TEXTURE_WIDTH; x++) {
			for(int y = 0; y < TEXTURE_HEIGHT; y++) {
				wall_texture[TEXTURE_HEIGHT * y + x] = (x % 16 && y % 16) ? 0x00EEEEEE : 0x0000000000;
			}
		}
		int textureOffsetX;
		if (g_rays[i].was_hit_ver)
			textureOffsetX = (int)g_rays[i].wall_hit_y % TEXTURE_HEIGHT;
		else
			textureOffsetX = (int)g_rays[i].wall_hit_x % TEXTURE_WIDTH;
		for(int y = wall_top_pixel; y < wall_bottom_pixel; y++) {
			int distanceFromTop = y + (wall_strip_height / 2) - (IMG_HEIGHT / 2);
			int textureOffsetY = distanceFromTop * ((float)TEXTURE_HEIGHT / wall_strip_height);

			int texelColor = wall_texture[(TEXTURE_HEIGHT * textureOffsetY) + textureOffsetX];
			mlx_pixel_put_img(i, y, texelColor);
		}



		for(int y = wall_bottom_pixel; y < IMG_HEIGHT; y++)
			mlx_pixel_put_img(i, y, 0x00777777);
		i++;
	}
}
