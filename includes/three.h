/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:07:23 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/17 18:52:25 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREE_H
# define THREE_H

# include "cub3d.h"

# define FOV_ANG 1.047198

typedef	struct	s_texture
{
	void		*txt[5];
	char		*file[5];
	int			w[5];
	int			h[5];
	int			color;
	int			*texel[5];
	int			bpp;
	int			line_length;
	int			endian;
	int			offset_x;
	int			offset_y;
}				t_texture;
t_texture		g_texture;

float			g_distance_proj_plane;

void			textures(void);
void			render_3d(void);
void			ceiling(int i, int wall_top_pixel);
void			grounding(int i, int wall_t_p, int wall_b_p, int wall_strip_h);
void			flooring(int i, int wall_bottom_pixel);
void			what_index(int i, int *index);

#endif
