/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/27 19:17:06 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void    basic_reading(void)
{
	int		fd;
	char    *line;
	int     ret;
	
	fd = open("./map.cub", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
}