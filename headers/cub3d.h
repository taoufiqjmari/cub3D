/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:46:38 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/23 18:02:03 by tjmari           ###   ########.fr       */
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
# define FLT_MAX 340282346638528859811704183484516925440.000000

# define MINIMAP_SCALE_FACTOR 0.2
# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 33
# define TILE_SIZE 64
# define WIN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WIN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANG (60 * (M_PI / 180))
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS (WIN_WIDTH / WALL_STRIP_WIDTH)

# define CLICK_LEFT 0
# define CLICK_RIGHT 2
# define CLICK_DOWN 1
# define CLICK_UP 13
# define CLICK_LEFT_VIEW 123
# define CLICK_RIGHT_VIEW 124
# define CLICK_ESC 53

typedef	struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;
t_mlx			g_mlx;

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

typedef	struct	s_texture
{
	void		*txt;
	char		*file;
	int			width;
	int			height;
	int			color;
	int			*texel;
	int			bpp;
	int			line_length;
	int			endian;
}				t_texture;
t_texture		g_texture;

void			setup(void);
void			update(void);
void			render(void);
void			render_map(void);
void			map(int tile_x, int tile_y, int i, int j);
void			define_ply(int tile_x, int tile_y);
void			update_player(void);
_Bool			map_has_wall_at(float new_ply_x, float new_ply_y);
// void			render_player(void);
void			update_rays(void);
void			cast_ray(float ray_ang, int strip_id);
_Bool			rays_map_has_wall_at(float new_x, float new_y);
float			distance_between_points(float x1, float y1, float x2, float y2);
void			render_rays(void);
void			sprite(int tile_x, int tile_y);
void			render_3d(void);
int				key_pressed(int keycode, t_ply *g_ply);
void			rect(int i, int j, int color);
// void			circle(int i, int j, int color);
void			line(int x1, int y1, int color);
void			mlx_pixel_put_img(int x, int y, int color);
float			normalize_ang(float ang);
double			rad(double degrees);
double			deg(double radians);
int				abs(int n);
void			my_exit(int errno);
int				red_cross(void);

#endif
