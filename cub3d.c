/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/10/26 19:24:11 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const int g_map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// typedef	struct	s_player
// {
//     float		x;
//     float		y;
//     float		width;
//     float		height;
//     int			turnDirection; // -1 for left, +1 for right
//     int			walkDirection; // -1 for back, +1 for front
//     float		rotationAngle;
//     float		walkSpeed;
//     float		turnSpeed;
// } 				t_player;

int		window_init(t_vars *vars)
{
	if (!(vars->mlx_ptr = mlx_init()))
	{
		// Handle error msg
		return (FALSE);
	}
	if (!(vars->win_ptr = mlx_new_window(vars->mlx_ptr, RES_X, RES_Y, "cub3D")))
	{
		// Handle error msg
		return (FALSE);
	}
	return (TRUE);
}

// void 	setup(t_player *player)
// {
// 	player->x = WINDOW_WIDTH / 2;
//     player->y = WINDOW_HEIGHT / 2;
//     player->width = 5;
//     player->height = 5;
//     player->turnDirection = 0;
//     player->walkDirection = 0;
//     player->rotationAngle = PI / 2;
//     player->walkSpeed = 100;
//     player->turnSpeed = 45 * (PI / 180);
// }

void	draw_rect(t_vars *vars, int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < TILE_SIZE)
	{
		y = 0;
		while (y < TILE_SIZE)
		{
			mlx_pixel_put(vars->mlx_ptr, vars->win_ptr,
							(x + i) * MINIMAP_SCALE_FACTOR,
							(y + j) * MINIMAP_SCALE_FACTOR, color);
			y++;
		}
		x++;
	}
}

void	render_map(t_vars *vars)
{
	int	i;
	int j;
	int tile_x;
	int tile_y;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			if (g_map[i][j] == 1)
				draw_rect(vars, tile_x, tile_y, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	render(t_vars *vars)
{
	render_map(vars);
}

int		main(void)
{
	t_vars		vars;
	// t_player	player;

	// setup(&player);
	if (window_init(&vars))
	{
		render(&vars);
		mlx_loop(vars.mlx_ptr);
	}
	return (0);
}
