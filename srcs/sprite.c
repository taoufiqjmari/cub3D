/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:59:19 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/24 12:02:58 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sprite.h"

void	sprite(int tile_x, int tile_y)
{
	rect(tile_x, tile_y, 0x00BF4040);
}

void	salloc(void)
{
	if (!(g_sprites = malloc(sizeof(t_sprites) * g_sprite.count)))
		my_exit("sprite allocation failed");
}

void	put_data(int i, int j)
{
	static int	index = 0;

	i += TILE_SIZE / 2;
	j += TILE_SIZE / 2;
	g_sprites[index].x = j;
	g_sprites[index].y = i;
	index++;
}

void	sprite_data(void)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (i < g_elements.map_height)
	{
		j = 0;
		while (j < g_elements.map_width)
		{
			if (g_elements.map[i][j] == '2')
				put_data(i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	get_distance(void)
{
	int		i;

	i = 0;
	while (i < g_sprite.count)
	{
		g_sprites[i].distance = distance_between_points(g_ply.ply_x, g_ply.ply_y, g_sprites[i].x, g_sprites[i].y);
		g_sprites[i].angle = atan2(g_sprites[i].y - g_ply.ply_y , g_sprites[i].x - g_ply.ply_x);
		if ((g_ply.rotation_ang - FOV_ANG / 2) - g_sprites[i].angle > rad(180))
			g_sprites[i].angle += rad(360);
		if (g_sprites[i].angle - (g_ply.rotation_ang - FOV_ANG / 2) > rad(180))
			g_sprites[i].angle -= rad(360);
		i++;
	}
}

void	ft_sort(void)
{
	int			i;
	t_sprites	temp;

	i = 0;
	while (i < g_sprite.count)
	{
		if (g_sprites[i].distance < g_sprites[i + 1].distance)
		{
			temp = g_sprites[i + 1];
			g_sprites[i + 1] = g_sprites[i];
			g_sprites[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	put_spixel_to_img(int x, int y)
{
	char *dst;
	
	if (x >= g_mlx.win_width || y >= g_mlx.win_height)
		return ;
	if (y < g_mlx.win_height && y >= 0 && g_sprite.color != 0x000000)
	{
			dst = g_mlx.addr + (y * g_mlx.line_length +
							x * (g_mlx.bits_per_pixel / 8));
		*(unsigned int*)dst = g_sprite.color;
	}
}

void	draw_sprite(int x, float distance, float strip_height)
{
	int		i;
	int		j;
	int		y;

	i = x;
	while (i <= x + strip_height)
	{
		j = (g_mlx.win_height - strip_height) / 2;
		y = 0;
		if (i >= 0 && i < g_mlx.win_width && distance < g_rays[i].distance)
		{
			while (j < (g_mlx.win_height + strip_height) / 2 - 1)
			{
				g_sprite.color = g_sprite.texel[(int)(y / strip_height * g_sprite.h)
					* g_sprite.w + (int)((i - x) / strip_height * g_sprite.w)];
				put_spixel_to_img(i, j);
				j++;
				y++;
			}
		}
		i++;
	}
}

void	render_sprite(void)
{
	int		i;
	float	strip_height;
	int		window_index;
	
	i = 0;
	get_distance();
	ft_sort();
	while (i < g_sprite.count)
	{
		strip_height = (TILE_SIZE / g_sprites[i].distance) * g_distance_proj_plane;
		window_index = (g_sprites[i].angle - (g_ply.rotation_ang - FOV_ANG / 2))
						/ (FOV_ANG / g_mlx.win_width) - (strip_height / 2);
		draw_sprite(window_index, g_sprites[i].distance, strip_height);
		i++;
	}
}