/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:26 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/16 17:46:11 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	my_exit(int errno)
{
	if(errno == 0)
		printf("ESC Clicked!\n");
	else if(errno == 1)
		printf("Red X Clicked!\n");
	else if (errno == 2)
		printf("Problem with mlx_init()\n");
	else if (errno == 3)
		printf("Problem with mlx_new_window()\n");
	else if (errno == 4)
		printf("Problem with mlx_new_image()\n");
	exit(0);
}

int		red_cross(void)
{
	my_exit(1);
	return (0);
}
