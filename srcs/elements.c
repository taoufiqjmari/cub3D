/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:19:12 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/28 12:01:03 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	validate_r(char *line)
{
	size_t	len;
	char	**part;
	char	*temp;

	len = ft_strlen(line);
	if (!g_file.r)
	{
		g_file.r = 1;
		if (ft_strncmp(line, "R ", 2)
			|| *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Resolution input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 3)
		{
			is_info_correct(*(part + 1), 'r');
			temp = *(part + 1);
			*(part + 1) = ft_strtrim(*(part + 1), "0");
			free(temp);
			if (ft_strlen(*(part + 1)) > 4)
				g_mlx.win_w = 2560;
			else
			{
				g_mlx.win_w = atoi(*(part + 1));
				g_mlx.win_w = g_mlx.win_w > 2560 ? 2560 : g_mlx.win_w;
			}
			is_info_correct(*(part + 2), 'r');
			temp = *(part + 2);
			*(part + 2) = ft_strtrim(*(part + 2), "0");
			free(temp);
			if (ft_strlen(*(part + 2)) > 4)
				g_mlx.win_h = 1440;
			else
			{
				g_mlx.win_h = atoi(*(part + 2));
				g_mlx.win_h = g_mlx.win_h > 1440 ? 1440 : g_mlx.win_h;
			}
		}
		else
			my_exit("Resolution input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("Resolution input is in wrong format");
}

void	validate_f(char *line)
{
	g_file.len = ft_strlen(line);
	if (!g_file.f)
	{
		pre_fc(&line, 'f');
		if (how_many_part(g_file.part) == 2)
		{
			g_file.rgb = ft_split(*(g_file.part + 1), ',');
			if (how_many_part(g_file.rgb) == 3)
			{
				pre_rgb(g_file.rgb, 'r');
				check_rgb_f(*g_file.rgb, 'r');
				pre_rgb(g_file.rgb, 'g');
				check_rgb_f(*(g_file.rgb + 1), 'g');
				pre_rgb(g_file.rgb, 'b');
				check_rgb_f(*(g_file.rgb + 2), 'b');
				g_fc.f = g_fc.f_r << 16 | g_fc.f_g << 8 | g_fc.f_b;
			}
			else
				my_exit("Floor RGB input is in wrong format");
			free_dpointer(g_file.rgb);
		}
		else
			my_exit("Floor RGB input is in wrong format");
		free_dpointer(g_file.part);
	}
	else
		my_exit("Floor RGB input is in wrong format");
}

void	validate_c(char *line)
{
	g_file.len = ft_strlen(line);
	if (!g_file.c)
	{
		pre_fc(&line, 'c');
		if (how_many_part(g_file.part) == 2)
		{
			g_file.rgb = ft_split(*(g_file.part + 1), ',');
			if (how_many_part(g_file.rgb) == 3)
			{
				pre_rgb(g_file.rgb, 'r');
				check_rgb_c(*g_file.rgb, 'r');
				pre_rgb(g_file.rgb, 'g');
				check_rgb_c(*(g_file.rgb + 1), 'g');
				pre_rgb(g_file.rgb, 'b');
				check_rgb_c(*(g_file.rgb + 2), 'b');
				g_fc.c = g_fc.c_r << 16 | g_fc.c_g << 8 | g_fc.c_b;
			}
			else
				my_exit("Ceiling RGB input is in wrong format");
			free_dpointer(g_file.rgb);
		}
		else
			my_exit("Ceiling RGB input is in wrong format");
		free_dpointer(g_file.part);
	}
	else
		my_exit("Ceiling RGB input is in wrong format");
}

void	textures(void)
{
	g_texture.texel[0] = (int *)mlx_get_data_addr(g_texture.txt[0],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[1] = (int *)mlx_get_data_addr(g_texture.txt[1],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[2] = (int *)mlx_get_data_addr(g_texture.txt[2],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_texture.texel[3] = (int *)mlx_get_data_addr(g_texture.txt[3],
			&g_texture.bpp, &g_texture.line_length, &g_texture.endian);
	g_sprite.texel = (int *)mlx_get_data_addr(g_sprite.txt,
			&g_sprite.bpp, &g_sprite.line_length, &g_sprite.endian);
}
