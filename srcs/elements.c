/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:19:12 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 15:20:03 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	validate_r(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_elements.r)
	{
		g_elements.r = 1;
		if (ft_strncmp(line, "R ", 2) || *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Resolution input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 3)
		{
			is_info_correct(*(part + 1), 'r');
			*(part + 1) = ft_strtrim(*(part + 1), "0");
			if (ft_strlen(*(part + 1)) > 4)
				g_mlx.win_width = 2560;
			else
			{
				g_mlx.win_width = atoi(*(part + 1));
				g_mlx.win_width = g_mlx.win_width > 2560 ? 2560 : g_mlx.win_width;
			}
			is_info_correct(*(part + 2), 'r');
			*(part + 2) = ft_strtrim(*(part + 2), "0");
			if (ft_strlen(*(part + 2)) > 4)
				g_mlx.win_height = 1440;
			else
			{
				g_mlx.win_height = atoi(*(part + 2));
				g_mlx.win_height = g_mlx.win_height > 1440 ? 1440 : g_mlx.win_height;
			}
		}
		else
			my_exit("Resolution input is in wrong format");
	}
	else
		my_exit("Resolution input is in wrong format");
}

void	validate_no(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_elements.no)
	{
		g_elements.no = 1;
		if (ft_strncmp(line, "NO ", 3) || *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("North texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (open(*(part + 1), O_RDONLY) > 0)
				g_texture.file[0] = *(part + 1);
			else
				my_exit("North texture input is in wrong format");
		}
		else
			my_exit("North texture input is in wrong format");
	}
	else
		my_exit("North texture input is in wrong format");
}

void	validate_so(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_elements.so)
	{
		g_elements.so = 1;
		if (ft_strncmp(line, "SO ", 3) || *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("South texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (open(*(part + 1), O_RDONLY) > 0)
				g_texture.file[1] = *(part + 1);
			else
				my_exit("South texture input is in wrong format");
		}
		else
			my_exit("South texture input is in wrong format");
	}
	else
		my_exit("South texture input is in wrong format");
}

void	validate_we(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_elements.we)
	{
		g_elements.we = 1;
		if (ft_strncmp(line, "WE ", 3) || *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("West texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (open(*(part + 1), O_RDONLY) > 0)
				g_texture.file[2] = *(part + 1);
			else
				my_exit("West texture input is in wrong format");
		}
		else
			my_exit("West texture input is in wrong format");
	}
	else
		my_exit("West texture input is in wrong format");
}

void	validate_ea(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_elements.ea)
	{
		g_elements.ea = 1;
		if (ft_strncmp(line, "EA ", 3) || *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("East texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (open(*(part + 1), O_RDONLY) > 0)
				g_texture.file[3] = *(part + 1);
			else
				my_exit("East texture input is in wrong format");
		}
		else
			my_exit("East texture input is in wrong format");
	}
	else
		my_exit("East texture input is in wrong format");
}

void	validate_s(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_elements.s)
	{
		g_elements.s = 1;
		if (ft_strncmp(line, "S ", 2) || *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Sprite texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (open(*(part + 1), O_RDONLY) > 0)
				g_sprite.texture = *(part + 1);
			else
				my_exit("Sprite texture input is in wrong format");
		}
		else
			my_exit("Sprite texture input is in wrong format");
	}
	else
		my_exit("Sprite texture input is in wrong format");
}

void	validate_f(char *line)
{
	size_t	len;
	char	**part;
	char	**rgb;

	len = ft_strlen(line);
	if (!g_elements.f)
	{
		g_elements.f = 1;
		if (ft_strncmp(line, "F ", 2) || *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Floor RGB input is in wrong format");
		is_info_correct(line, 'c');
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			rgb = ft_split(*(part + 1), ',');
			if (how_many_part(rgb) == 3)
			{
				is_info_correct(*rgb, 'r');
				*rgb = ft_strtrim(*rgb, "0");
				if (ft_strlen(*rgb) <= 3)
				{
					g_fc.floor_r = ft_atoi(*rgb);
					if (!(g_fc.floor_r >= 0 && g_fc.floor_r <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
				is_info_correct(*(rgb + 1), 'r');
				*(rgb + 1) = ft_strtrim(*(rgb + 1), "0");
				if (ft_strlen(*(rgb + 1)) <= 3)
				{
					g_fc.floor_g = ft_atoi(*(rgb + 1));
					if (!(g_fc.floor_g >= 0 && g_fc.floor_g <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
				is_info_correct(*(rgb + 2), 'r');
				*(rgb + 2) = ft_strtrim(*(rgb + 2), "0");
				if (ft_strlen(*(rgb + 2)) <= 3)
				{
					g_fc.floor_b = ft_atoi(*(rgb + 2));
					if (!(g_fc.floor_b >= 0 && g_fc.floor_b <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
				g_fc.floor = create_trgb(g_fc.floor_r, g_fc.floor_g, g_fc.floor_b);
			}
			else
				my_exit("Floor RGB input is in wrong format");
		}
		else
			my_exit("Floor RGB input is in wrong format");
	}
	else
		my_exit("Floor RGB input is in wrong format");
}

void	validate_c(char *line)
{
	size_t	len;
	char	**part;
	char	**rgb;

	len = ft_strlen(line);
	if (!g_elements.c)
	{
		g_elements.c = 1;
		if (ft_strncmp(line, "C ", 2) || *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Ceiling RGB input is in wrong format");
		is_info_correct(line, 'c');
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			rgb = ft_split(*(part + 1), ',');
			if (how_many_part(rgb) == 3)
			{
				is_info_correct(*rgb, 'r');
				*rgb = ft_strtrim(*rgb, "0");
				if (ft_strlen(*rgb) <= 3)
				{
					g_fc.ceiling_r = ft_atoi(*rgb);
					if (!(g_fc.ceiling_r >= 0 && g_fc.ceiling_r <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
				is_info_correct(*(rgb + 1), 'r');
				*(rgb + 1) = ft_strtrim(*(rgb + 1), "0");
				if (ft_strlen(*(rgb + 1)) <= 3)
				{
					g_fc.ceiling_g = ft_atoi(*(rgb + 1));
					if (!(g_fc.ceiling_g >= 0 && g_fc.ceiling_g <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
				is_info_correct(*(rgb + 2), 'r');
				*(rgb + 2) = ft_strtrim(*(rgb + 2), "0");
				if (ft_strlen(*(rgb + 2)) <= 3)
				{
					g_fc.ceiling_b = ft_atoi(*(rgb + 2));
					if (!(g_fc.ceiling_b >= 0 && g_fc.ceiling_b <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
				g_fc.ceiling = create_trgb(g_fc.ceiling_r, g_fc.ceiling_g, g_fc.ceiling_b);
			}
			else
				my_exit("Ceiling RGB input is in wrong format");
		}
		else
			my_exit("Ceiling RGB input is in wrong format");
	}
	else
		my_exit("Ceiling RGB input is in wrong format");
}