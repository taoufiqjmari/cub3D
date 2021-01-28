/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:13:27 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/28 09:52:07 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bmp.h"

void	file(void)
{
	if (!(g_fd = open("screenshot.bmp", O_WRONLY | O_CREAT, S_IRUSR
						| S_IWUSR | S_IRGRP | S_IROTH)))
	{
		my_exit("bmp not created");
	}
}

void	make_header(void)
{
	g_bmp.byte_type[0] = 'B';
	g_bmp.byte_type[1] = 'M';
	g_bmp.byte_size = (g_mlx.win_w *
					g_mlx.win_h * 3) + 54;
	g_bmp.byte_reserved = 0x00000000;
	g_bmp.byte_offset = 0x36;
	g_bmp.header_size = 40;
	g_bmp.image_width = g_mlx.win_w;
	g_bmp.image_height = -g_mlx.win_h;
	g_bmp.color_planes = 1;
	g_bmp.bits_per_pixel = 32;
	g_bmp.compression = 0;
	g_bmp.image_size = (g_mlx.win_w * g_mlx.win_h * 4);
	g_bmp.bits_xpels_per_meter = 2835;
	g_bmp.bits_xpels_per_meter = 2835;
	g_bmp.total_colors = 0;
	g_bmp.important_colors = 0;
}

void	write_header(void)
{
	write(g_fd, &g_bmp.byte_type, 2);
	write(g_fd, &g_bmp.byte_size, 4);
	write(g_fd, &g_bmp.byte_reserved, 4);
	write(g_fd, &g_bmp.byte_offset, 4);
	write(g_fd, &g_bmp.header_size, 4);
	write(g_fd, &g_bmp.image_width, 4);
	write(g_fd, &g_bmp.image_height, 4);
	write(g_fd, &g_bmp.color_planes, 2);
	write(g_fd, &g_bmp.bits_per_pixel, 2);
	write(g_fd, &g_bmp.compression, 4);
	write(g_fd, &g_bmp.image_size, 4);
	write(g_fd, &g_bmp.bits_xpels_per_meter, 4);
	write(g_fd, &g_bmp.bits_ypels_per_meter, 4);
	write(g_fd, &g_bmp.total_colors, 4);
	write(g_fd, &g_bmp.important_colors, 4);
}

void	write_file(void)
{
	char				*pixel_array;
	unsigned int		i;
	int					j;

	if (!(pixel_array = malloc(sizeof(char) * g_bmp.image_size)))
		my_exit("write file error");
	i = -1;
	j = 0;
	g_bmp.image_size /= 4;
	while (++i < g_bmp.image_size)
	{
		pixel_array[j++] = g_mlx.addr[i] & 255;
		pixel_array[j++] = (g_mlx.addr[i] & 255 << 8) >> 8;
		pixel_array[j++] = (g_mlx.addr[i] & 255 << 16) >> 16;
		j++;
	}
	write(g_fd, pixel_array, g_bmp.image_size *= 4);
	free(pixel_array);
}

void	bmp(void)
{
	ft_bzero(&g_bmp, sizeof(t_bmp));
	file();
	make_header();
	write_header();
	write_file();
	close(g_fd);
}
