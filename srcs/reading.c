/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/28 11:39:21 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	reading_file(void)
{
	char	*line;
	int		ret;
	char	*temp;

	init_elements();
	ret = 1;
	while (ret)
	{
		ret = get_next_line(g_file.fd, &line);
		if (!g_file.read)
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
			{
				free(line);
				continue ;
			}
			else
				my_exit("Error in file");
			all_read();
		}
		else
		{
			if (*line == '\0' && !g_file.start_map)
			{
				free(line);
				continue ;
			}
			else if (*line != '\0')
			{
				g_file.start_map = 1;
				temp = g_file.temp_map;
				g_file.temp_map = ft_strjoin(g_file.temp_map, "\n");
				free(temp);
				temp = g_file.temp_map;
				g_file.temp_map = ft_strjoin(g_file.temp_map, line);
				free(temp);
				if (g_file.map_width < ft_strlen(line))
					g_file.map_width = ft_strlen(line);
				g_file.map_height++;
			}
			else
				my_exit("space inside map");
		}
		free(line);
	}
}

void	final_map(void)
{
	size_t	i;

	i = 0;
	g_file.map_splitted = ft_split(g_file.temp_map, '\n');
	free(g_file.temp_map);
	g_file.map = (char **)malloc(sizeof(char *) * (g_file.map_height + 1));
	while (i < g_file.map_height)
	{
		g_file.map[i] = (char *)malloc(sizeof(char) * g_file.map_width);
		ft_strlcpy(g_file.map[i], g_file.map_splitted[i], g_file.map_width);
		i++;
	}
	g_file.map[i] = NULL;
	free_dpointer(g_file.map_splitted);
}

void	map_parsing(void)
{
	size_t	i;
	size_t	j;

	if (!ft_strchr(g_file.temp_map, 'N') && !ft_strchr(g_file.temp_map, 'E')
		&& !ft_strchr(g_file.temp_map, 'S') && !ft_strchr(g_file.temp_map, 'W'))
		my_exit("no player in map");
	i = 0;
	while (i < g_file.map_height)
	{
		j = 0;
		while (j < g_file.map_width)
		{
			if (g_file.map[i][j] != ' ' && g_file.map[i][j] != '1')
				to_check(i, j);
			j++;
		}
		i++;
	}
}

void	to_check(size_t i, size_t j)
{
	if (i == 0 || j == 0 || i == g_file.map_height - 1
		|| j == g_file.map_width - 1)
		my_exit("map is not closed");
	else if (g_file.map[i][j] == '0')
	{
		if (g_file.map[i][j + 1] == ' ' || g_file.map[i][j - 1] == ' '
				|| g_file.map[i - 1][j] == ' ' || g_file.map[i + 1][j] == ' ')
			my_exit("0 next to space");
	}
	else if (g_file.map[i][j] == 'N' || g_file.map[i][j] == 'W'
			|| g_file.map[i][j] == 'E' || g_file.map[i][j] == 'S')
	{
		if (g_file.map[i][j + 1] == ' ' || g_file.map[i][j - 1] == ' '
			|| g_file.map[i - 1][j] == ' ' || g_file.map[i + 1][j] == ' ')
			my_exit("player next to space");
		g_ply.ply_init_dir = g_file.map[i][j];
		define_ply(i, j);
	}
	else if (g_file.map[i][j] == '2')
		sprite(i, j);
	else
		my_exit("invalid character in map");
}
