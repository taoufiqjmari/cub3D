/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:59:19 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/17 17:58:59 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	sprite(int tile_x, int tile_y)
{
	rect(tile_x, tile_y, 0x00FFE6E6);
	circle(tile_x + TILE_SIZE / 2,
				tile_y + TILE_SIZE / 2,
				0x00BF4040);
}
