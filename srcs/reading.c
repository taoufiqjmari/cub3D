/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/20 09:56:53 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reading.h"

void	init_elements(void)
{
	g_elements.r = 0;
	g_elements.no = 0;
	g_elements.so = 0;
	g_elements.we = 0;
	g_elements.ea = 0;
	g_elements.s = 0;
	g_elements.f = 0;
	g_elements.c = 0;
	g_elements.read = 0;
	g_elements.start_map = 0;
	g_elements.temp_map = "";
	g_elements.map_width = 0;
	g_elements.map_height = 0;
}

void	all_read(void)
{
	if (g_elements.r && g_elements.no && g_elements.so
		&& g_elements.we && g_elements.ea && g_elements.s
		&& g_elements.f && g_elements.c)
		g_elements.read = 1;
}

int		how_many_part(char **part)
{
	int		i;

	i = 0;
	while (part[i])
		i++;
	return (i);
}

int		create_trgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

void	is_info_correct(char *part, char c)
{
	int		commas;

	commas = 0;
	if (c == 'r')
	{
		while (*part)
		{
			if (*part >= '0' && *part <= '9')
				part++;
			else if (*part == '\0')
				return ;
			else
				my_exit("Error in file");
		}
	}
	if (c == 'c')
	{
		while (*part)
		{
			if (*part == ',')
				commas++;
			part++;
		}
		if (commas != 2)
			my_exit("Error in file");
	}
}

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
				printf("%s\n", *rgb);
				*rgb = ft_strtrim(*rgb, "0");
				printf("%s\n", *rgb);
				if (ft_strlen(*rgb) <= 3)
				{
					g_fc.floor_r = ft_atoi(*rgb);
					if (!(g_fc.floor_r >= 0 && g_fc.floor_r <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
					
				printf("%s\n", *(rgb + 1));
				*(rgb + 1) = ft_strtrim(*(rgb + 1), "0");
				printf("%s\n", *(rgb + 1));
				if (ft_strlen(*(rgb + 1)) <= 3)
				{
					g_fc.floor_g = ft_atoi(*(rgb + 1));
					if (!(g_fc.floor_g >= 0 && g_fc.floor_g <= 255))
						my_exit("Floor RGB input is in wrong format");
				}
				else
					my_exit("Floor RGB input is in wrong format");
					
				printf("%s\n", *(rgb + 2));
				*(rgb + 2) = ft_strtrim(*(rgb + 2), "0");
				printf("%s\n", *(rgb + 2));
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
				*rgb = ft_strtrim(*rgb, "0");
				if (ft_strlen(*rgb) <= 3)
				{
					g_fc.ceiling_r = ft_atoi(*rgb);
					if (!(g_fc.ceiling_r >= 0 && g_fc.ceiling_r <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
					
				*(rgb + 1) = ft_strtrim(*(rgb + 1), "0");
				if (ft_strlen(*(rgb + 1)) <= 3)
				{
					g_fc.ceiling_g = ft_atoi(*(rgb + 1));
					if (!(g_fc.ceiling_g >= 0 && g_fc.ceiling_g <= 255))
						my_exit("Ceiling RGB input is in wrong format");
				}
				else
					my_exit("Ceiling RGB input is in wrong format");
					
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

void	reading_file(void)
{
	int		fd;
	char	*line;
	int		ret;

	init_elements();
	fd = open("./map.cub", O_RDONLY);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
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
	size_t		i;
	size_t		j;

	i = 0;
	while (g_elements.map[i])
	{
		j = 0;
		while (j < g_elements.map_width)
		{
			if (g_elements.map[i][j] != '1' && g_elements.map[i][j] != ' ')
				to_check(i, j);
			j++;
		}
		i++;
	}
}

void	to_check(size_t i, size_t j)
{
	if (i - 1 < 0 || j - 1 < 0 || i + 1 >= g_elements.map_height
		|| j + 1 >= g_elements.map_width)
		my_exit("map not closed");
	else if (g_elements.map[i][j] == '0')
	{
		if (g_elements.map[i][j - 1] == ' ' || g_elements.map[i][j + 1] == ' '
			|| g_elements.map[i - 1][j] == ' ' || g_elements.map[i + 1][j] == ' ')
			my_exit("spaces inside map");
	}
	// else if (g_elements.map[i][j] == 'N' || g_elements.map[i][j] == 'W'
	// 		|| g_elements.map[i][j] == 'E' || g_elements.map[i][j] == 'S')
	// 		define_ply();
	// else if (g_elements.map[i][j] == '2')
	// 	sprite();
	// else
	// 	my_exit("invalid character in map");
}