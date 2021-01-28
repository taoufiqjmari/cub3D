/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:27:51 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/28 10:07:35 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	validate_no(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_file.no)
	{
		g_file.no = 1;
		if (ft_strncmp(line, "NO ", 3)
			|| *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("North texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (!(g_texture.txt[0] = mlx_xpm_file_to_image(g_mlx.mlx, part[1],
				&g_texture.w[0], &g_texture.h[0])))
				my_exit("North texture input is in wrong format");
		}
		else
			my_exit("North texture input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("North texture input is in wrong format");
}

void	validate_so(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_file.so)
	{
		g_file.so = 1;
		if (ft_strncmp(line, "SO ", 3)
			|| *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("South texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (!(g_texture.txt[1] = mlx_xpm_file_to_image(g_mlx.mlx, part[1],
				&g_texture.w[1], &g_texture.h[1])))
				my_exit("South texture input is in wrong format");
		}
		else
			my_exit("South texture input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("South texture input is in wrong format");
}

void	validate_we(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_file.we)
	{
		g_file.we = 1;
		if (ft_strncmp(line, "WE ", 3)
			|| *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("West texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (!(g_texture.txt[2] = mlx_xpm_file_to_image(g_mlx.mlx, part[1],
				&g_texture.w[2], &g_texture.h[2])))
				my_exit("West texture input is in wrong format");
		}
		else
			my_exit("West texture input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("West texture input is in wrong format");
}

void	validate_ea(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_file.ea)
	{
		g_file.ea = 1;
		if (ft_strncmp(line, "EA ", 3)
			|| *(line + 3) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("East texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (!(g_texture.txt[3] = mlx_xpm_file_to_image(g_mlx.mlx, part[1],
				&g_texture.w[3], &g_texture.h[3])))
				my_exit("East texture input is in wrong format");
		}
		else
			my_exit("East texture input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("East texture input is in wrong format");
}

void	validate_s(char *line)
{
	size_t	len;
	char	**part;

	len = ft_strlen(line);
	if (!g_file.s)
	{
		g_file.s = 1;
		if (ft_strncmp(line, "S ", 2)
			|| *(line + 2) == ' ' || *(line + (len - 1)) == ' ')
			my_exit("Sprite texture input is in wrong format");
		part = ft_split(line, ' ');
		if (how_many_part(part) == 2)
		{
			if (!(g_sprite.txt = mlx_xpm_file_to_image(g_mlx.mlx, part[1],
				&g_sprite.w, &g_sprite.h)))
				my_exit("Sprite texture input is in wrong format");
		}
		else
			my_exit("Sprite texture input is in wrong format");
		free_dpointer(part);
	}
	else
		my_exit("Sprite texture input is in wrong format");
}
