/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/10/27 20:35:58 by tjmari           ###   ########.fr       */
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

int		init_setup(void)
{
	g_vars.p_x = WINDOW_WIDTH / 2;
	g_vars.p_y = WINDOW_HEIGHT / 2;
	g_vars.p_width = 1;
	g_vars.p_height = 1;
	g_vars.p_turn_direction = 0;
	g_vars.p_walk_direction = 0;
	g_vars.p_rotation_angle = PI / 2;
	g_vars.p_walk_speed = 1;
	g_vars.p_turn_speed = 45 * (PI / 180);
	if (!(g_vars.mlx = mlx_init()))
		return (FALSE);
	if (!(g_vars.win = mlx_new_window(g_vars.mlx, RES_X, RES_Y, "cub3D")))
		return (FALSE);
	if (!(g_vars.img = mlx_new_image(g_vars.mlx, 1300, 900)))
		return (FALSE);
	g_vars.addr = mlx_get_data_addr(g_vars.img, &g_vars.bits_per_pixel,
									&g_vars.size_line, &g_vars.endian);
	return (TRUE);
}

/*
**	rendering
*/

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = g_vars.addr + (y * g_vars.size_line
						+ x * (g_vars.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rect(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < TILE_SIZE)
	{
		y = 0;
		while (y < TILE_SIZE)
		{
			my_mlx_pixel_put((x + i) * MINIMAP_SCALE_FACTOR,
							(y + j) * MINIMAP_SCALE_FACTOR, color);
			y++;
		}
		x++;
	}
}

void	render_map(void)
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
				draw_rect(tile_x, tile_y, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void	DDA(int x0, int y0, int x1, int y1 , int color)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float Xinc = dx / (float) steps;
	float Yinc = dy / (float) steps;

	float x = x0;
	float y = y0;
	for (int i = 0; i <= steps; i++)
	{
		my_mlx_pixel_put(x * MINIMAP_SCALE_FACTOR,
							y * MINIMAP_SCALE_FACTOR, color);
		x += Xinc;
		y += Yinc;
	}
}

void	render_player(int color)
{
	int x;
	int y;

	x = g_vars.p_x;
	while (x < g_vars.p_x + g_vars.p_width)
	{
		y = g_vars.p_y;
		while (y < g_vars.p_y + g_vars.p_height)
		{
			my_mlx_pixel_put(x * MINIMAP_SCALE_FACTOR,
							y * MINIMAP_SCALE_FACTOR, color);
			y++;
		}
		x++;
	}
	DDA(g_vars.p_x, g_vars.p_y, 
		g_vars.p_x + cos(g_vars.p_rotation_angle) * 40,
		g_vars.p_y + sin(g_vars.p_rotation_angle) * 40, color);
}

void	render(void)
{
	render_map();
	render_player(0x0000FF00);
}

/*
**	process_input
*/

void movePlayer(void) {
    g_vars.p_rotation_angle += g_vars.p_turn_direction * g_vars.p_turn_speed;
    float moveStep = g_vars.p_walk_direction * g_vars.p_walk_speed;

    float newPlayerX = g_vars.p_x + cos(g_vars.p_rotation_angle) * moveStep;
    float newPlayerY = g_vars.p_y + sin(g_vars.p_rotation_angle) * moveStep;

    g_vars.p_x = newPlayerX;
    g_vars.p_y = newPlayerY;
}

int		red_x(void)
{
	mlx_destroy_window(g_vars.mlx, g_vars.win);
	exit(0);
}

int		key_hook_pressed(int keycode, t_vars *g_vars)
{
	render_player(0x000000);
	if (keycode == 53)
	{
		mlx_destroy_window(g_vars->mlx, g_vars->win);
		exit(0);
	}
	else if (keycode == 125)
		g_vars->p_walk_direction -= 1;
	else if (keycode == 126)
		g_vars->p_walk_direction += 1;
	else if (keycode == 124)
		g_vars->p_turn_direction += 1;
	else if (keycode == 123)
		g_vars->p_turn_direction -= 1;
	render_map();
	movePlayer();
	render_player(0x0000FF00);
	mlx_put_image_to_window(g_vars->mlx, g_vars->win, g_vars->img, 0, 0);

	return (0);
}

int		key_hook_released(int keycode, t_vars *g_vars)
{
	if (keycode == 125)
		g_vars->p_walk_direction = 0;
	else if (keycode == 126)
		g_vars->p_walk_direction = 0;
	else if (keycode == 124)
		g_vars->p_turn_direction = 0;
	else if (keycode == 123)
		g_vars->p_turn_direction = 0;
	return (0);
}

void	process_input(void)
{
	mlx_hook(g_vars.win, 2, 1L << 0, key_hook_pressed, &g_vars);
	mlx_hook(g_vars.win, 17, 0L, red_x, &g_vars);
	mlx_hook(g_vars.win, 3, 1L << 1, key_hook_released, &g_vars);
}

int		main(void)
{
	if (!(init_setup()))
		exit(0);
	else
	{
		render();
		mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_vars.img, 0, 0);
		process_input();
		mlx_loop(g_vars.mlx);
	}
	return (0);
}
