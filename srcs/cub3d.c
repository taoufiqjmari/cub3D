/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/17 18:13:38 by tjmari           ###   ########.fr       */
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
		g_ply.ply_init_dir = g_map[i][j];
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
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
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

	map_index_x = floor(new_ply_x / TILE_SIZE);
	map_index_y = floor(new_ply_y / TILE_SIZE);
	return (g_map[map_index_y][map_index_x] == ' ' ||
			g_map[map_index_y][map_index_x] == '1' ||
			g_map[map_index_y][map_index_x] == '2');
}

void	cast_ray(float ray_ang, int strip_id)
{
	ray_ang = normalize_ang(ray_ang);
	strip_id = 0;
	return ;
}

int		key_pressed(int keycode, t_ply *g_ply)
{
	g_ply->straight = 1;
	if (keycode == LEFT)
	{
		g_ply->walk_direction = -1;
		g_ply->straight = 0;
	}
	else if (keycode == RIGHT)
	{
		g_ply->walk_direction = +1;
		g_ply->straight = 0;
	}
	else if (keycode == DOWN || keycode == 125)
		g_ply->walk_direction = -1;
	else if (keycode == UP || keycode == 126)
		g_ply->walk_direction = +1;
	else if (keycode == LEFT_VIEW)
		g_ply->turn_direction = -1;
	else if (keycode == RIGHT_VIEW)
		g_ply->turn_direction = +1;
	else if (keycode == ESC)
		my_exit(0);
	render();
	return (0);
}

void	setup(void)
{
	if (!(g_mlx.mlx = mlx_init()))
		my_exit(2);
	// g_init.tile_size = 64;
	// g_init.img_width = MAP_NUM_COLS * g_init.tile_size;
	// g_init.img_height = MAP_NUM_ROWS * g_init.tile_size;
	g_mlx.win_width = IMG_WIDTH + TILE_SIZE;
	g_mlx.win_height = IMG_HEIGHT + TILE_SIZE;
	if (!(g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, g_mlx.win_width,
										g_mlx.win_height, "cub3D")))
		my_exit(3);
	if (!(g_img.img = mlx_new_image(g_mlx.mlx,
								IMG_WIDTH, IMG_HEIGHT)))
		my_exit(4);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel,
										&g_img.line_length, &g_img.endian);
	g_img.img_x = (g_mlx.win_width - IMG_WIDTH) / 2;
	g_img.img_y = (g_mlx.win_height - IMG_HEIGHT) / 2;
	g_ply.player_defined = 0;
	g_ply.turn_direction = 0;
	g_ply.walk_direction = 0;
	g_ply.move_speed = 5.0;
	g_ply.rotation_speed = rad(5);
}

void	update(void)
{
	update_player();
	// update_rays();
}

void	render(void)
{
	update();
	render_map();
	// render_rays();
	render_player();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win,
								g_img.img, g_img.img_x, g_img.img_y);
}

int		main(void)
{
	setup();
	render();
	mlx_hook(g_mlx.mlx_win, 2, 1L << 0, key_pressed, &g_ply);
	mlx_hook(g_mlx.mlx_win, 17, 0L, red_cross, &g_mlx);
	mlx_loop(g_mlx.mlx);
	return (0);
}
