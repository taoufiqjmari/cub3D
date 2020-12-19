/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/19 20:52:02 by tjmari           ###   ########.fr       */
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

_Bool	map_has_wall_at(float new_x, float new_y)
{
	int	map_index_x;
	int	map_index_y;
	int	angle;
	int	x;
	int	y;

	angle = 0;
	while (angle < 360)
	{
		x = new_x + cos(rad(angle));
		y = new_y + sin(rad(angle));
		map_index_x = x / TILE_SIZE;
		map_index_y = y / TILE_SIZE;
		if (g_map[map_index_y][map_index_x] == ' ' ||
			g_map[map_index_y][map_index_x] == '1' ||
			g_map[map_index_y][map_index_x] == '2')
			return (1);
		angle += 90;
	}
	return (0);
}

////////////////////////////////////////////////////////////////
//						RAYS_CODE_START						////
////////////////////////////////////////////////////////////////

void	cast_ray(float ray_ang, int strip_id)
{
	ray_ang = normalize_ang(ray_ang);

	int		is_ray_facing_down = ray_ang > rad(0) && ray_ang < rad(180);
	int		is_ray_facing_up = !is_ray_facing_down;
	int		is_ray_facing_right = ray_ang > rad(270) || ray_ang < rad(90);
	int		is_ray_facing_left = !is_ray_facing_right;

	float	xintercept, yintercept;
	float	xstep, ystep;

	/*
	**	HORIZONTAL RAY_GRID INTERSECTION
	*/
	int		found_horz_wall_hit = FALSE;
	float	horz_wall_hit_x = 0;
	float	horz_wall_hit_y = 0;
	int		horz_wall_content = 0;

	// Find the y-coordinate of the closest horizontal grid intersection
	yintercept = floor(g_ply.ply_y / TILE_SIZE) * TILE_SIZE;
	yintercept += is_ray_facing_down ? TILE_SIZE : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	xintercept = g_ply.ply_x + (yintercept - g_ply.ply_y) / tan(ray_ang);

	// Calculate the increment xstep and ystep
	ystep = TILE_SIZE;
	ystep *= is_ray_facing_up ? -1 : 1;

	xstep = TILE_SIZE / tan(ray_ang);
	xstep *= (is_ray_facing_left && xstep > 0) ? -1 : 1;
	xstep *= (is_ray_facing_right && xstep < 0) ? -1 : 1;

	float next_horz_touch_x = xintercept;
	float next_horz_touch_y = yintercept;

	// Increment xstep and ystep until we find a wall
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= IMG_WIDTH && next_horz_touch_y >= 0 && next_horz_touch_y <= IMG_HEIGHT)
	{
		float x_to_check = next_horz_touch_x;
		float y_to_check = next_horz_touch_y + (is_ray_facing_up ? -1 : 0);

		if(map_has_wall_at(x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
			horz_wall_hit_y = next_horz_touch_y;
			horz_wall_content = g_map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
			found_horz_wall_hit = TRUE;
			break;
		}
		else
		{
			next_horz_touch_x += xstep;
			next_horz_touch_y += ystep;
		}
	}

	/*
	**	VERTICAL RAY_GRID INTERSECTION
	*/
	int		found_vert_wall_hit = FALSE;
	float	vert_wall_hit_x = 0;
	float	vert_wall_hit_y = 0;
	int		vert_wall_content = 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	xintercept = floor(g_ply.ply_x / TILE_SIZE) * TILE_SIZE;
	xintercept += is_ray_facing_right ? TILE_SIZE : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	yintercept = g_ply.ply_y + (xintercept - g_ply.ply_x) * tan(ray_ang);

	// Calculate the increment xstep and ystep
	xstep = TILE_SIZE;
	xstep *= is_ray_facing_left ? -1 : 1;

	ystep = TILE_SIZE * tan(ray_ang);
	ystep *= (is_ray_facing_up && ystep > 0) ? -1 : 1;
	ystep *= (is_ray_facing_down && ystep < 0) ? -1 : 1;

	float next_vert_touch_x = xintercept;
	float next_vert_touch_y = yintercept;

	// Increment xstep and ystep until we find a wall
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= IMG_WIDTH && next_vert_touch_y >= 0 && next_vert_touch_y <= IMG_HEIGHT)
	{
		float x_to_check = next_vert_touch_x + (is_ray_facing_left ? -1 : 0);
		float y_to_check = next_vert_touch_y;

		if(map_has_wall_at(x_to_check, y_to_check))
		{
			vert_wall_hit_x = next_vert_touch_x;
			vert_wall_hit_y = next_vert_touch_y;
			vert_wall_content = g_map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)];
			found_vert_wall_hit = TRUE;
			break;
		}
		else
		{
			next_vert_touch_x += xstep;
			next_vert_touch_y += ystep;
		}
	}

	// Calculate both horizontal and vertical hit distances and choose the smallest one
	float	horz_hit_distance = found_horz_wall_hit
		? distance_between_points(g_ply.ply_x, g_ply.ply_y, horz_wall_hit_x, horz_wall_hit_y)
		: INT_MAX;
	float	vert_hit_distance = found_vert_wall_hit
		? distance_between_points(g_ply.ply_x, g_ply.ply_y, vert_wall_hit_x, vert_wall_hit_y)
		: INT_MAX;

	if(vert_hit_distance < horz_hit_distance)
	{
		g_rays[strip_id].distance = vert_hit_distance;
		g_rays[strip_id].wall_hit_x = vert_wall_hit_x;
		g_rays[strip_id].wall_hit_y = vert_wall_hit_y;
		g_rays[strip_id].wall_hit_content = vert_wall_content;
		g_rays[strip_id].was_hit_ver = TRUE;
	}
	else
	{
		g_rays[strip_id].distance = horz_hit_distance;
		g_rays[strip_id].wall_hit_x = horz_wall_hit_x;
		g_rays[strip_id].wall_hit_y = horz_wall_hit_y;
		g_rays[strip_id].wall_hit_content = horz_wall_content;
		g_rays[strip_id].was_hit_ver = FALSE;
	}
	g_rays[strip_id].ray_ang = ray_ang;
	g_rays[strip_id].is_ray_down = is_ray_facing_down;
	g_rays[strip_id].is_ray_up = is_ray_facing_up;
	g_rays[strip_id].is_ray_left = is_ray_facing_left;
	g_rays[strip_id].is_ray_right = is_ray_facing_right;
}

////////////////////////////////////////////////////////////////
//						RAYS_CODE_END						////
////////////////////////////////////////////////////////////////

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
	update_rays();
}

void	render(void)
{
	update();
	render_map();
	render_player();
	render_rays();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win,
								g_img.img, g_img.img_x, g_img.img_y);
}

int		main(void)
{
	setup();
	render_map();
	render();
	mlx_hook(g_mlx.mlx_win, 2, 1L << 0, key_pressed, &g_ply);
	mlx_hook(g_mlx.mlx_win, 17, 0L, red_cross, &g_mlx);
	mlx_loop(g_mlx.mlx);
	return (0);
}
