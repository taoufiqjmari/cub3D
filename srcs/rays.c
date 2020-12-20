/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:51:35 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/20 18:48:06 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	update_rays(void)
{
	float	ray_ang;
	int		strip_id;

	ray_ang = g_ply.rotation_ang - (FOV_ANG / 2);
	strip_id = 0;
	while (strip_id < NUM_RAYS)
	{
		cast_ray(ray_ang, strip_id);
		ray_ang += FOV_ANG / NUM_RAYS;
		strip_id++;
	}
}

void	render_rays(void)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		line(MINIMAP_SCALE_FACTOR * g_rays[i].wall_hit_x,
				MINIMAP_SCALE_FACTOR * g_rays[i].wall_hit_y,
				0x000000FF);
		i++;
	}
}
