/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:27:51 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/21 08:54:27 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/three.h"

void	textures(void)
{
	if (!(g_texture.txt[0] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[0],
		&g_texture.w[0], &g_texture.h[0])))
		my_exit("mlx_xpm_file_to_image() failed");
	if (!(g_texture.txt[1] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[1],
		&g_texture.w[1], &g_texture.h[1])))
		my_exit("mlx_xpm_file_to_image() failed");
	if (!(g_texture.txt[2] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[2],
		&g_texture.w[2], &g_texture.h[2])))
		my_exit("mlx_xpm_file_to_image() failed");
	if (!(g_texture.txt[3] = mlx_xpm_file_to_image(g_mlx.mlx, g_texture.file[3],
		&g_texture.w[3], &g_texture.h[3])))
		my_exit("mlx_xpm_file_to_image() failed");
	g_texture.texel[0] = (int *)mlx_get_data_addr(g_texture.txt[0],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[1] = (int *)mlx_get_data_addr(g_texture.txt[1],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[2] = (int *)mlx_get_data_addr(g_texture.txt[2],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[3] = (int *)mlx_get_data_addr(g_texture.txt[3],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
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
