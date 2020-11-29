/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:46:38 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/29 12:14:47 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 33

typedef	struct	s_init
{
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
	int			tile_size;
	float		img_x;
	float		img_y;

	float		ply_x;
	float		ply_y;
	int			radius;
	int			turn_direction;
	int			walk_direction;
	float		rotation_angle;
	float		move_speed;
	float		rotation_speed;
}				t_init;
t_init			g_init;

void			setup(void);
void			update(void);
void			draw(void);
void			render_map(void);
void			render_player(void);
void			draw_rect(int i, int j, int color);
void			draw_circle(int i, int j, int color);
void			draw_line(int x0, int y0, int x1, int y1);
void			mlx_pixel_put_img(int x, int y, int color);
int				abs (int n);

#endif
