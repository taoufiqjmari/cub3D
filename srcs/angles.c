/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:20:48 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/27 12:45:04 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	deg(double radians)
{
	return (radians * (180.0 / M_PI));
}

float	normalize_ang(float ang)
{
	if (ang < rad(0))
		ang += rad(360);
	else if (ang > rad(360))
		ang -= rad(360);
	return (ang);
}
