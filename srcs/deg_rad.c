/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:20:48 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 20:11:06 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

double	rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	deg(double radians)
{
	return (radians * (180.0 / M_PI));
}
