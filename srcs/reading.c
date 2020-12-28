/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/28 09:37:10 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

char	**info;
char	**colors;

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	handle_r(char *line)
{
	info = ft_split(line, ' ');
	g_mlx.win_width = ft_atoi(*(info + 1));
	g_mlx.win_height = ft_atoi(*(info + 2));
}

void	handle_no(char *line)
{
	info = ft_split(line, ' ');
	g_texture.file[0] = *(info + 1);
}

void	handle_so(char *line)
{
	info = ft_split(line, ' ');
	g_texture.file[1] = *(info + 1);
}

void	handle_we(char *line)
{
	info = ft_split(line, ' ');
	g_texture.file[2] = *(info + 1);
}

void	handle_ea(char *line)
{
	info = ft_split(line, ' ');
	g_texture.file[3] = *(info + 1);
}

void	handle_s(char *line)
{
	info = ft_split(line, ' ');
	// g_texture.file[4] = *(info + 1);
}

void	handle_f(char *line)
{
	info = ft_split(line, ' ');
	colors = ft_split(*(info + 1), ',');
	g_texture.r_ceiling = atoi(*(colors + 0));
	g_texture.g_ceiling = atoi(*(colors + 1));
	g_texture.b_ceiling = atoi(*(colors + 2));
	g_texture.ceiling_color = create_trgb(0, g_texture.r_ceiling, g_texture.g_ceiling, g_texture.b_ceiling);
}

void	handle_c(char *line)
{
	info = ft_split(line, ' ');
	colors = ft_split(*(info + 1), ',');
	g_texture.r_floor = atoi(*(colors + 0));
	g_texture.g_floor = atoi(*(colors + 1));
	g_texture.b_floor = atoi(*(colors + 2));
	g_texture.floor_color = create_trgb(0, g_texture.r_floor, g_texture.g_floor, g_texture.b_floor);
}

void    basic_reading(void)
{
	int		fd;
	char    *line;
	int     read;
	
	fd = open("./map.cub", O_RDONLY);
	while ((read = get_next_line(fd, &line)) > 0)
	{
		if (*line == 'R')
			handle_r(line);
		else if (*line == 'N')
			handle_no(line);
		else if (*line == 'S' && *(line + 1) == 'O')
			handle_so(line);
		else if (*line == 'W')
			handle_we(line);
		else if (*line == 'E')
			handle_ea(line);
		else if (*line == 'S' && *(line + 1) != 'O')
			handle_s(line);
		else if (*line == 'F')
			handle_f(line);
		else if (*line == 'C')
			handle_c(line);
	}
}