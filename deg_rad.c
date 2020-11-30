/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:20:48 by tjmari            #+#    #+#             */
/*   Updated: 2020/11/30 17:52:13 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	rad_deg(double radians)
{
	return (radians * (180.0 / M_PI));
}
