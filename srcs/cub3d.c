/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 20:40:13 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	g_map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '1'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1'},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '0', 'N', '0', '1', '1', '1', ' ', ' '},
	{'1', '1', '1', '1', '0', '1', '1', '1', ' ', '1', '1', '1', '0', '1', '0', '1', ' ', '1', '0', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1', ' ', ' ', ' ', ' '},
	{'1', '1', '1', '1', '1', '1', '1', '1', ' ', '1', '1', '1', '1', '1', '1', '1', ' ', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', ' ', ' ', ' ', ' '}
};

void	map(int tile_x, int tile_y, int i, int j)
{
	if (g_map[i][j] == '1')
		rect(tile_x, tile_y, 0x00ADADAD);
	else if (g_map[i][j] == '2')
		sprite(tile_x, tile_y);
	else if (g_map[i][j] == 'W' || g_map[i][j] == 'E'
				|| g_map[i][j] == 'S' || g_map[i][j] == 'N')
	{
		g_init.ply_init_dir = g_map[i][j];
		define_ply(tile_x, tile_y);
	}
	else if (g_map[i][j] == ' ')
		return ;
	else
		rect(tile_x, tile_y, 0x00F9F9F9);
}

void	render_map(void)
{
	int	i;
	int	j;
	int	tile_x;
	int	tile_y;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * g_init.tile_size;
			tile_y = i * g_init.tile_size;
			map(tile_x, tile_y, i, j);
			j++;
		}
		i++;
	}
}

_Bool	map_has_wall_at(float new_ply_x, float new_ply_y)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = floor(new_ply_x / g_init.tile_size);
	map_index_y = floor(new_ply_y / g_init.tile_size);
	return (g_map[map_index_y][map_index_x] == ' ' ||
			g_map[map_index_y][map_index_x] == '1' ||
			g_map[map_index_y][map_index_x] == '2');
}

int		key_pressed(int keycode, t_init *g_init)
{
	g_init->straight = 1;
	if (keycode == LEFT)
	{
		g_init->walk_direction = -1;
		g_init->straight = 0;
	}
	else if (keycode == RIGHT)
	{
		g_init->walk_direction = +1;
		g_init->straight = 0;
	}
	else if (keycode == DOWN)
		g_init->walk_direction = -1;
	else if (keycode == UP)
		g_init->walk_direction = +1;
	else if (keycode == LEFT_VIEW)
		g_init->turn_direction = -1;
	else if (keycode == RIGHT_VIEW)
		g_init->turn_direction = +1;
	else if (keycode == ESC)
		my_exit(0);
	render();
	return (0);
}

void	setup(void)
{
	if (!(g_init.mlx = mlx_init()))
		my_exit(2);
	g_init.tile_size = 64;
	g_init.img_width = MAP_NUM_COLS * g_init.tile_size;
	g_init.img_height = MAP_NUM_ROWS * g_init.tile_size;
	g_init.win_width = g_init.img_width + g_init.tile_size;
	g_init.win_height = g_init.img_height + g_init.tile_size;
	if (!(g_init.mlx_win = mlx_new_window(g_init.mlx, g_init.win_width,
										g_init.win_height, "cub3D")))
		my_exit(3);
	if (!(g_init.img = mlx_new_image(g_init.mlx,
								g_init.img_width, g_init.img_height)))
		my_exit(4);
	g_init.addr = mlx_get_data_addr(g_init.img, &g_init.bits_per_pixel,
										&g_init.line_length, &g_init.endian);
	g_init.img_x = (g_init.win_width - g_init.img_width) / 2;
	g_init.img_y = (g_init.win_height - g_init.img_height) / 2;
	g_init.player_defined = 0;
	g_init.turn_direction = 0;
	g_init.walk_direction = 0;
	g_init.move_speed = 5.0;
	g_init.rotation_speed = rad(5);
}

void	update(void)
{
	update_player();
}

void	render(void)
{
	update();
	render_map();
	render_player();
	mlx_put_image_to_window(g_init.mlx, g_init.mlx_win,
								g_init.img, g_init.img_x, g_init.img_y);
}

int		main(void)
{
	setup();
	render();
	mlx_hook(g_init.mlx_win, 2, 1L << 0, key_pressed, &g_init);
	mlx_hook(g_init.mlx_win, 17, 0L, red_cross, &g_init);
	mlx_loop(g_init.mlx);
	return (0);
}
