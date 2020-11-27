/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/27 18:24:29 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	map[map_num_rows][map_num_cols] = {
		{'0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '1'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0' ,'0'},
		{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0'},
		{'1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0'},
		{'1', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0'},
		{'1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', '0', '0', 'N', '1', '1', '0', '0'},
		{'1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0'}
	};

void	mlx_pixel_put_img(int x, int y, int color)
{
	char	*dst;

	dst = g_init.addr + (y * g_init.line_length + x * (g_init.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rect(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < g_init.tile_size)
	{
		y = 0;
		while (y < g_init.tile_size)
		{
			mlx_pixel_put_img((x + i) * g_init.minimap_scale_factor,
							(y + j) * g_init.minimap_scale_factor, color);
			y++;
		}
		x++;
	}
}

void	render_map(void)
{
	int i;
	int j;
	int tile_x;
	int tile_y;

	i = 0;
	while(i < map_num_rows)
	{
		j = 0;
		while(j < map_num_cols)
		{
			tile_x = j * g_init.tile_size;
			tile_y = i * g_init.tile_size;
			if(map[i][j] == '1')
				draw_rect(tile_x, tile_y, 0x00FFFFFF);
			else if(map[i][j] == '2')
				draw_rect(tile_x, tile_y, 0x00BF4040);
			else if(map[i][j] == 'N' || map[i][j] == 'R' || map[i][j] == 'S' || map[i][j] == 'W')
				draw_rect(tile_x, tile_y, 0x0040BF40);
			else
				draw_rect(tile_x, tile_y, 0x00999999);
			j++;
		}
		i++;
	}
}

void	setup(void)
{
		g_init.mlx = mlx_init();
		g_init.tile_size = 64;
		g_init.img_width = map_num_cols * g_init.tile_size;
		g_init.img_height = map_num_rows * g_init.tile_size;
		g_init.win_width = g_init.img_width + 128;
		g_init.win_height = g_init.img_height + 128;
		g_init.mlx_win = mlx_new_window(g_init.mlx, g_init.win_width, g_init.win_height, "cub3D");

		g_init.img = mlx_new_image(g_init.mlx, g_init.img_width, g_init.img_height);
		g_init.addr = mlx_get_data_addr(g_init.img, &g_init.bits_per_pixel, &g_init.line_length,
										&g_init.endian);
		g_init.img_x = (g_init.win_width - g_init.img_width) / 2;
		g_init.img_y = (g_init.win_height - g_init.img_height) / 2;
		g_init.minimap_scale_factor = 1.0;
}

void	update(void)
{

}

void	draw(void)
{
	update();

	render_map();
}

int		main(void)
{
	setup();
	update();
	draw();
	mlx_put_image_to_window(g_init.mlx, g_init.mlx_win, g_init.img, g_init.img_x, g_init.img_y);
	mlx_loop(g_init.mlx);
	return (0);
}
