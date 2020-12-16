/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:46:38 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 20:38:28 by tjmari           ###   ########.fr       */
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

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define LEFT_VIEW 123
# define RIGHT_VIEW 124
# define ESC 53

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

	_Bool		player_defined;
	char		ply_init_dir;
	float		ply_x;
	float		ply_y;
	int			radius;
	int			turn_direction;
	int			walk_direction;
	float		rotation_ang;
	_Bool		straight;
	float		move_speed;
	float		rotation_speed;
}				t_init;
t_init			g_init;

struct			s_line
{
	int			dx;
	int			dy;
	int			steps;
	float		x_inc;
	float		y_inc;
	float		x;
	float		y;
	int			i;
};

void			setup(void);
void			update(void);
void			render(void);
void			render_map(void);
void			map(int tile_x, int tile_y, int i, int j);
void			define_ply(int tile_x, int tile_y);
void			update_player(void);
void			normalize_degree(void);
void			render_player(void);
void			sprite(int tile_x, int tile_y);
int				key_pressed(int keycode, t_init *g_init);
void			rect(int i, int j, int color);
void			circle(int i, int j, int color);
void			line(int x0, int y0, int x1, int y1);
_Bool			map_has_wall_at(float new_ply_x, float new_ply_y);
void			mlx_pixel_put_img(int x, int y, int color);
double			rad(double degrees);
double			deg(double radians);
int				abs(int n);
void			my_exit(int errno);
int				red_cross(void);

#endif
