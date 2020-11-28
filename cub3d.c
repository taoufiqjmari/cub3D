/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/28 20:54:48 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	g_map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '1'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', 'N', '0', '1', '1', '1', ' ', ' '},
	{'1', '1', '1', '1', '0', '1', '1', '1', ' ', '1', '1', '1', '0', '1', '0', '1', ' ', '1', '0', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '1', '1', '1', '1', '1', '1', ' ', '1', '1', '1', '1', '1', '1', '1', ' ', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', ' ', ' ', ' ', ' '}
};

void	mlx_pixel_put_img(int x, int y, int color)
{
	char	*dst;

	dst = g_init.addr + (y * g_init.line_length +
							x * (g_init.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render_map(void)
{
	int i;
	int j;
	int tile_x;
	int tile_y;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * g_init.tile_size;
			tile_y = i * g_init.tile_size;
			if (g_map[i][j] == '1')
				draw_rect(tile_x, tile_y, 0x00FFFFFF);
			else if (g_map[i][j] == '2')
				draw_rect(tile_x, tile_y, 0x00BF4040);
			else if (g_map[i][j] == 'N' || g_map[i][j] == 'R'
						|| g_map[i][j] == 'S' || g_map[i][j] == 'W')
			{
				draw_rect(tile_x, tile_y, 0x00999999);
				g_init.ply_x = tile_x;
				g_init.ply_y = tile_y;
				render_player();
			}
			else if (g_map[i][j] == ' ')
			{
				j++;
				continue;
			}
			else
				draw_rect(tile_x, tile_y, 0x00999999);
			j++;
		}
		i++;
	}
}

void	render_player(void)
{
	draw_rect2(g_init.ply_x + g_init.tile_size / 2 - 5, g_init.ply_y + g_init.tile_size / 2 - 5, 0x0000FF);
	draw_line(g_init.ply_x + g_init.tile_size / 2,
				g_init.ply_y + g_init.tile_size / 2,
				g_init.ply_x + cos(g_init.rotation_angle) * 100 + g_init.tile_size / 2,
				g_init.ply_y + sin(g_init.rotation_angle) * 100 + g_init.tile_size / 2
			);
}

void	update_player(void)
{

}

void	setup(void)
{
	g_init.mlx = mlx_init();
	g_init.tile_size = 64;
	g_init.img_width = MAP_NUM_COLS * g_init.tile_size;
	g_init.img_height = MAP_NUM_ROWS * g_init.tile_size;
	g_init.win_width = g_init.img_width + 64;
	g_init.win_height = g_init.img_height + 64;
	g_init.mlx_win = mlx_new_window(g_init.mlx, g_init.win_width,
										g_init.win_height, "cub3D");

	g_init.img = mlx_new_image(g_init.mlx,
								g_init.img_width, g_init.img_height);
	g_init.addr = mlx_get_data_addr(g_init.img, &g_init.bits_per_pixel,
										&g_init.line_length, &g_init.endian);
	g_init.img_x = (g_init.win_width - g_init.img_width) / 2;
	g_init.img_y = (g_init.win_height - g_init.img_height) / 2;

	g_init.turn_direction = 0;
	g_init.walk_direction = 0;
	g_init.rotation_angle = M_PI / 2;
	g_init.move_speed = 2.0;
	g_init.rotation_speed = 3 * (M_PI / 180);
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
	mlx_put_image_to_window(g_init.mlx, g_init.mlx_win,
								g_init.img, g_init.img_x, g_init.img_y);
	mlx_loop(g_init.mlx);
	return (0);
}
