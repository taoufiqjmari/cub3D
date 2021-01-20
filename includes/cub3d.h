/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:46:38 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/20 08:26:15 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "reading.h"
# include "map.h"
# include "player.h"
# include "rays.h"
# include "three.h"
# include "sprite.h"
# include "angles.h"
# include "draw.h"

# define FALSE 0
# define TRUE 1

# define MINIMAP_SCALE_FACTOR 0.2
# define MAP_NUM_ROWS 14
# define MAP_NUM_COLS 14
# define TILE_SIZE 64

char	g_map[MAP_NUM_ROWS][MAP_NUM_COLS];

typedef	struct	s_mlx
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
}				t_mlx;
t_mlx			g_mlx;

void			setup(void);
void			render(void);
void			my_exit(const char *str);
int				red_cross(void);

#endif
