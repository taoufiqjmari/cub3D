/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:19:12 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/28 10:21:28 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	validate_r(char *line)
{
	size_t	len;
	char	**part;
	char	*tmp;

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
			tmp = *(part + 1);
			*(part + 1) = ft_strtrim(*(part + 1), "0");
			free(tmp);
			if (ft_strlen(*(part + 1)) > 4)
				g_mlx.win_w = 2560;
			else
			{
				g_mlx.win_w = atoi(*(part + 1));
				g_mlx.win_w = g_mlx.win_w > 2560 ? 2560 : g_mlx.win_w;
			}
			is_info_correct(*(part + 2), 'r');
			tmp = *(part + 2);
			*(part + 2) = ft_strtrim(*(part + 2), "0");
			free(tmp);
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
	size_t	len;
	char	**part;
	char	**rgb;
	char	*tmp;

	len = ft_strlen(line);
	if (!g_file.f)
	{
		g_file.f = 1;
		if (ft_strncmp(line, "F ", 2)
			|| *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Floor RGB input is in wrong format");
		is_info_correct(line, 'c');
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			rgb = ft_split(*(part + 1), ',');
			if (how_many_part(rgb) == 3)
			{
				is_info_correct(*rgb, 'r');
				tmp = *rgb;
				*rgb = ft_strtrim(*rgb, "0");
				free(tmp);
				if (ft_strlen(*rgb) <= 3)
				{
					g_fc.f_r = ft_atoi(*rgb);
					if (!(g_fc.f_r >= 0 && g_fc.f_r <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
				is_info_correct(*(rgb + 1), 'r');
				tmp = *(rgb + 1);
				*(rgb + 1) = ft_strtrim(*(rgb + 1), "0");
				free(tmp);
				if (ft_strlen(*(rgb + 1)) <= 3)
				{
					g_fc.f_g = ft_atoi(*(rgb + 1));
					if (!(g_fc.f_g >= 0 && g_fc.f_g <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
				is_info_correct(*(rgb + 2), 'r');
				tmp = *(rgb + 2);
				*(rgb + 2) = ft_strtrim(*(rgb + 2), "0");
				free(tmp);
				if (ft_strlen(*(rgb + 2)) <= 3)
				{
					g_fc.f_b = ft_atoi(*(rgb + 2));
					if (!(g_fc.f_b >= 0 && g_fc.f_b <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
				g_fc.f = g_fc.f_r << 16 | g_fc.f_g << 8 | g_fc.f_b;
			}
			else
				my_exit("Floor RGB input is in wrong format");
			free_dpointer(rgb);
		}
		else
			my_exit("Floor RGB input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("Floor RGB input is in wrong format");
}

void	validate_c(char *line)
{
	size_t	len;
	char	**part;
	char	**rgb;
	char	*tmp;

	len = ft_strlen(line);
	if (!g_file.c)
	{
		g_file.c = 1;
		if (ft_strncmp(line, "C ", 2)
			|| *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Ceiling RGB input is in wrong format");
		is_info_correct(line, 'c');
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			rgb = ft_split(*(part + 1), ',');
			if (how_many_part(rgb) == 3)
			{
				is_info_correct(*rgb, 'r');
				tmp = *rgb;
				*rgb = ft_strtrim(*rgb, "0");
				free(tmp);
				if (ft_strlen(*rgb) <= 3)
				{
					g_fc.c_r = ft_atoi(*rgb);
					if (!(g_fc.c_r >= 0 && g_fc.c_r <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
				is_info_correct(*(rgb + 1), 'r');
				tmp = *(rgb + 1);
				*(rgb + 1) = ft_strtrim(*(rgb + 1), "0");
				free(tmp);
				if (ft_strlen(*(rgb + 1)) <= 3)
				{
					g_fc.c_g = ft_atoi(*(rgb + 1));
					if (!(g_fc.c_g >= 0 && g_fc.c_g <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
				is_info_correct(*(rgb + 2), 'r');
				tmp = *(rgb + 2);
				*(rgb + 2) = ft_strtrim(*(rgb + 2), "0");
				free(tmp);
				if (ft_strlen(*(rgb + 2)) <= 3)
				{
					g_fc.c_b = ft_atoi(*(rgb + 2));
					if (!(g_fc.c_b >= 0 && g_fc.c_b <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
				g_fc.c = g_fc.c_r << 16 | g_fc.c_g << 8 | g_fc.c_b;
			}
			else
				my_exit("Ceiling RGB input is in wrong format");
			free_dpointer(rgb);
		}
		else
			my_exit("Ceiling RGB input is in wrong format");
		free_dpointer(part);
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
