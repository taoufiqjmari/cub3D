/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:59:19 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 18:09:17 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	sprite(int tile_x, int tile_y)
{
	rect(tile_x, tile_y, 0x00F9F9F9);
	circle(tile_x + g_init.tile_size / 2,
				tile_y + g_init.tile_size / 2,
				0x00BF4040);
}
