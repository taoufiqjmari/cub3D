/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:00:17 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 11:52:38 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "cub3d.h"

typedef	struct	s_ray
{
	float		ray_ang;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	_Bool		was_hit_ver;
	_Bool		is_ray_up;
	_Bool		is_ray_down;
	_Bool		is_ray_left;
	_Bool		is_ray_right;
	int			wall_hit_content;
}				t_rays;
t_rays			g_rays[2560];

void			update_rays(void);
void			cast_ray(float ray_ang, int strip_id);
_Bool			rays_map_has_wall_at(float new_x, float new_y);
float			pythagore(float x1, float y1, float x2, float y2);
void			render_rays(void);

#endif
