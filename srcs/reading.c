/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/10 10:44:03 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	basic_reading(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("./map.cub", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
	}
}
