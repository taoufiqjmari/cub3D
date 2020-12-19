/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:46:38 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/19 19:33:32 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define FALSE 0
# define TRUE 1
# define INT_MAX 2147483647
# define FLT_MAX 340282346638528859811704183484516925440.000000

# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 33
# define TILE_SIZE 64
# define IMG_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define IMG_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANG (60 * (M_PI / 180))
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS (IMG_WIDTH / WALL_STRIP_WIDTH)

# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define UP 13
# define LEFT_VIEW 123
# define RIGHT_VIEW 124
# define ESC 53

typedef	struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;
}				t_mlx;
t_mlx			g_mlx;

typedef	struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		img_x;
	float		img_y;
}				t_img;
t_img			g_img;

typedef	struct	s_ply
{
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
}				t_ply;
t_ply			g_ply;

typedef	struct	s_ray
{
	float		ray_ang;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			was_hit_ver;
	int			is_ray_up;
	int			is_ray_down;
	int			is_ray_left;
	int			is_ray_right;
	int			wall_hit_content;
}				t_rays;
t_rays			g_rays[NUM_RAYS];

typedef	struct	s_line
{
	int			dx;
	int			dy;
	int			steps;
	float		x_inc;
	float		y_inc;
	float		x;
	float		y;
	int			i;
}				t_line;

void			setup(void);
void			update(void);
void			render(void);
void			render_map(void);
void			map(int tile_x, int tile_y, int i, int j);
void			define_ply(int tile_x, int tile_y);
void			update_player(void);
void			render_player(void);
void			update_rays(void);
void			render_rays(void);
void			cast_ray(float ray_ang, int strip_id);
float			distance_between_points(float x1, float y1, float x2, float y2);
void			sprite(int tile_x, int tile_y);
int				key_pressed(int keycode, t_ply *g_ply);
void			rect(int i, int j, int color);
void			circle(int i, int j, int color);
void			line(int x0, int y0, int x1, int y1);
_Bool			map_has_wall_at(float new_ply_x, float new_ply_y);
void			mlx_pixel_put_img(int x, int y, int color);
float			normalize_ang(float ang);
double			rad(double degrees);
double			deg(double radians);
int				abs(int n);
void			my_exit(int errno);
int				red_cross(void);

#endif
