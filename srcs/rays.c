/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:51:35 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/17 19:01:06 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rays.h"

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

_Bool	rays_map_has_wall_at(float new_x, float new_y)
{
	int	map_index_x;
	int	map_index_y;

	map_index_x = new_x / TILE_SIZE;
	map_index_y = new_y / TILE_SIZE;
	return (g_map[map_index_y][map_index_x] == ' ' ||
			g_map[map_index_y][map_index_x] == '1' ||
			g_map[map_index_y][map_index_x] == '2');
}

void	cast_ray(float ray_ang, int strip_id)
{
	ray_ang = normalize_ang(ray_ang);

	int		is_ray_facing_down = ray_ang > rad(0) && ray_ang < rad(180);
	int		is_ray_facing_up = !is_ray_facing_down;
	int		is_ray_facing_right = ray_ang > rad(270) || ray_ang < rad(90);
	int		is_ray_facing_left = !is_ray_facing_right;

	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

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
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= MAP_NUM_COLS * TILE_SIZE && next_horz_touch_y >= 0 && next_horz_touch_y <= MAP_NUM_ROWS * TILE_SIZE)
	{
		float x_to_check = next_horz_touch_x;
		float y_to_check = next_horz_touch_y + (is_ray_facing_up ? -1 : 0);

		if (rays_map_has_wall_at(x_to_check, y_to_check))
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
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= MAP_NUM_COLS * TILE_SIZE && next_vert_touch_y >= 0 && next_vert_touch_y <= MAP_NUM_ROWS * TILE_SIZE)
	{
		float x_to_check = next_vert_touch_x + (is_ray_facing_left ? -1 : 0);
		float y_to_check = next_vert_touch_y;

		if (rays_map_has_wall_at(x_to_check, y_to_check))
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
		: MAXFLOAT;
	float	vert_hit_distance = found_vert_wall_hit
		? distance_between_points(g_ply.ply_x, g_ply.ply_y, vert_wall_hit_x, vert_wall_hit_y)
		: MAXFLOAT;

	if (vert_hit_distance < horz_hit_distance)
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

void	update_rays(void)
{
	float	ray_ang;
	int		strip_id;

	ray_ang = g_ply.rotation_ang - (FOV_ANG / 2);
	strip_id = 0;
	while (strip_id < WIN_WIDTH)
	{
		cast_ray(ray_ang, strip_id);
		ray_ang += FOV_ANG / WIN_WIDTH;
		strip_id++;
	}
}

void	render_rays(void)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		line(MINIMAP_SCALE_FACTOR * g_rays[i].wall_hit_x,
				MINIMAP_SCALE_FACTOR * g_rays[i].wall_hit_y,
				0x000000FF);
		i++;
	}
}
