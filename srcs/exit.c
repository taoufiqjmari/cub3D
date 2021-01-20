/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:38:26 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/20 09:45:44 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_exit(const char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(0);
}

int		red_cross(void)
{
	my_exit("Red X Clicked!");
	return (0);
}
