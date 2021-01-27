/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:27:51 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 18:53:13 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/three.h"

void	textures(void)
{
	g_texture.texel[0] = (int *)mlx_get_data_addr(g_texture.txt[0],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[1] = (int *)mlx_get_data_addr(g_texture.txt[1],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[2] = (int *)mlx_get_data_addr(g_texture.txt[2],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[3] = (int *)mlx_get_data_addr(g_texture.txt[3],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_sprite.texel = (int *)mlx_get_data_addr(g_sprite.txt,
			&g_sprite.bpp, &g_sprite.line_length, &g_sprite.endian);
}

void	what_index(int i, int *index)
{
	if (g_rays[i].is_ray_up && !g_rays[i].was_hit_ver)
		*index = 1;
	else if (g_rays[i].is_ray_down && !g_rays[i].was_hit_ver)
		*index = 0;
	else if (g_rays[i].is_ray_right && g_rays[i].was_hit_ver)
		*index = 2;
	else if (g_rays[i].is_ray_left && g_rays[i].was_hit_ver)
		*index = 3;
}
