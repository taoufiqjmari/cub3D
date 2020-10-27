/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:46:38 by tjmari            #+#    #+#             */
/*   Updated: 2020/10/27 20:14:41 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_vars {
	void		*mlx;
	void		*win;

	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	float		p_x;
	float		p_y;
	float		p_width;
	float		p_height;
	int			p_turn_direction;
	int			p_walk_direction;
	float		p_rotation_angle;
	float		p_walk_speed;
	float		p_turn_speed;
}				t_vars;

t_vars			g_vars;
# define FALSE 0
# define TRUE 1

# define RES_X 1920
# define RES_Y 1080

# define PI 3.14159265
# define TWO_PI 6.28318530

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# define MINIMAP_SCALE_FACTOR 1

# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANGLE (60 * (PI / 180))

# define NUM_RAYS WINDOW_WIDTH

# define FPS 30
# define FRAME_TIME_LENGTH (1000 / FPS)

#endif
