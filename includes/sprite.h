/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:09:39 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/22 15:47:02 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cub3d.h"

typedef struct  s_sprite
{
	int			count;
	char		*texture;
}				t_sprite;
t_sprite		g_sprite;

typedef struct  s_sprites
{
	int			x;
	int			y;
	float		distance;
	float		angle;
}				t_sprites;
t_sprites		*g_sprites;

void	sprite(int tile_x, int tile_y);

#endif
