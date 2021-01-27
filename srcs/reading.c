/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 15:28:47 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	reading_file(void)
{
	char	*line;
	int		ret;

	init_elements();
	ret = 1;
	while (ret)
	{
		ret = get_next_line(g_elements.fd, &line);
		if (!g_elements.read)
		{
			if (*line == 'R')
				validate_r(line);
			else if (*line == 'N')
				validate_no(line);
			else if (*line == 'S')
			{
				if (*(line + 1) == 'O')
					validate_so(line);
				else
					validate_s(line);
			}
			else if (*line == 'W')
				validate_we(line);
			else if (*line == 'E')
				validate_ea(line);
			else if (*line == 'F')
				validate_f(line);
			else if (*line == 'C')
				validate_c(line);
			else if (*line == '\0')
				continue ;
			else
				my_exit("Error in file");
			all_read();
		}
		else
		{
			if (*line == '\0' && !g_elements.start_map)
				continue ;
			else if (*line != '\0')
			{
				g_elements.start_map = 1;
				g_elements.temp_map = ft_strjoin(g_elements.temp_map, "\n");
				g_elements.temp_map = ft_strjoin(g_elements.temp_map, line);
				if (g_elements.map_width < ft_strlen(line))
					g_elements.map_width = ft_strlen(line);
				g_elements.map_height++;
			}
			else
				my_exit("space inside map");
		}
	}
}

void	final_map(void)
{
	size_t	i;

	i = 0;
	g_elements.map_splitted = ft_split(g_elements.temp_map, '\n');
	g_elements.map = (char **)malloc(sizeof(char *) * (g_elements.map_height + 1));
	while (i < g_elements.map_height)
	{
		g_elements.map[i] = (char *)malloc(sizeof(char) * g_elements.map_width);
		ft_strlcpy(g_elements.map[i], g_elements.map_splitted[i], g_elements.map_width);
		i++;
	}
	g_elements.map[i] = NULL;
}

void	map_parsing(void)
{
	size_t	i;
	size_t	j;

	if (!ft_strchr(g_elements.temp_map, 'N') && !ft_strchr(g_elements.temp_map, 'E')
		&& !ft_strchr(g_elements.temp_map, 'S') && !ft_strchr(g_elements.temp_map, 'W'))
		my_exit("no player in map");
	i = 0;
	while (i < g_elements.map_height)
	{
		j = 0;
		while (j < g_elements.map_width)
		{
			if (g_elements.map[i][j] != ' ' && g_elements.map[i][j] != '1')
				to_check(i, j);
			j++;
		}
		i++;
	}
}

void	to_check(size_t i, size_t j)
{
	if (i == 0 || j == 0 || i == g_elements.map_height - 1
		|| j == g_elements.map_width - 1)
		my_exit("map is not closed");
	else if (g_elements.map[i][j] == '0')
	{
		if (g_elements.map[i][j + 1] == ' ' || g_elements.map[i][j - 1] == ' '
				|| g_elements.map[i - 1][j] == ' ' || g_elements.map[i + 1][j] == ' ')
			my_exit("0 next to space");
	}
	else if (g_elements.map[i][j] == 'N' || g_elements.map[i][j] == 'W'
			|| g_elements.map[i][j] == 'E' || g_elements.map[i][j] == 'S')
	{
		if (g_elements.map[i][j + 1] == ' ' || g_elements.map[i][j - 1] == ' '
			|| g_elements.map[i - 1][j] == ' ' || g_elements.map[i + 1][j] == ' ')
			my_exit("player next to space");
		g_ply.ply_init_dir = g_elements.map[i][j];
		define_ply(i, j);
	}
	else if (g_elements.map[i][j] == '2')
	{
		if (g_elements.map[i][j + 1] == ' ' || g_elements.map[i][j - 1] == ' '
			|| g_elements.map[i - 1][j] == ' ' || g_elements.map[i + 1][j] == ' ')
			my_exit("sprite next to space");
		g_sprite.count++;
	}
	else
		my_exit("invalid character in map");
}
