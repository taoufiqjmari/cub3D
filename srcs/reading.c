/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:52:08 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/28 12:57:21 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

char	*ft_cub_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);

	else if (!s1)
	{
		if(!(s3 = (char *)malloc((ft_strlen(s2) + 1) * sizeof(char))))
			return (NULL);	
		i = 0;
		while (*s2)
		{
			s3[i] = *s2++;
			i++;
		}
		s3[i] = '\0';
		return (s3);
	}

	else if (!s2)
	{
		if(!(s3 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (*s1)
		{
			s3[i] = *s1++;
			i++;
		}
		s3[i] = '\0';
		return (s3);
	}

	else
	{
		s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!s3)
			return (NULL);
		i = 0;
		while (*s1)
		{
			s3[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			s3[i] = *s2++;
			i++;
		}
		s3[i] = '\0';
		return (s3);
	}
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	handle_r(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_mlx.win_width = ft_atoi(*(g_reading.info + 1));
	g_mlx.win_height = ft_atoi(*(g_reading.info + 2));
}

void	handle_no(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_texture.file[0] = *(g_reading.info + 1);
}

void	handle_so(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_texture.file[1] = *(g_reading.info + 1);
}

void	handle_we(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_texture.file[2] = *(g_reading.info + 1);
}

void	handle_ea(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_texture.file[3] = *(g_reading.info + 1);
}

void	handle_s(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_texture.file[4] = *(g_reading.info + 1);
}

void	handle_f(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_reading.colors = ft_split(*(g_reading.info + 1), ',');
	g_texture.r_ceiling = atoi(*(g_reading.colors + 0));
	g_texture.g_ceiling = atoi(*(g_reading.colors + 1));
	g_texture.b_ceiling = atoi(*(g_reading.colors + 2));
	g_texture.ceiling_color = create_trgb(0, g_texture.r_ceiling, g_texture.g_ceiling, g_texture.b_ceiling);
}

void	handle_c(char *line)
{
	g_reading.info = ft_split(line, ' ');
	g_reading.colors = ft_split(*(g_reading.info + 1), ',');
	g_texture.r_floor = atoi(*(g_reading.colors + 0));
	g_texture.g_floor = atoi(*(g_reading.colors + 1));
	g_texture.b_floor = atoi(*(g_reading.colors + 2));
	g_texture.floor_color = create_trgb(0, g_texture.r_floor, g_texture.g_floor, g_texture.b_floor);
}

void	first_read(char *line)
{
	if (g_reading.map_longest_line < (int)ft_strlen(line))
		g_reading.map_longest_line = (int)ft_strlen(line);
	g_reading.map_height++;
}

void	second_read(char *line)
{
	*(g_reading.other_map + g_reading.i) = NULL;
	*(g_reading.other_map + g_reading.i) = ft_cub_strjoin(*(g_reading.other_map + g_reading.i), line);
	printf("%s\n", *(g_reading.other_map + g_reading.i));
	g_reading.i++;
}

void	handle_map(char *line)
{
	if (!g_reading.sec_read)
		first_read(line);
	else
		second_read(line);
}

void    basic_reading(void)
{
	g_reading.fd = open("./map.cub", O_RDONLY);
	g_reading.read = 1;
	g_reading.sec_read = 0;
	g_reading.map_height = 0;
	g_reading.map_longest_line = 0;
	g_reading.i = 0;
	while (g_reading.read)
	{
		g_reading.read = get_next_line(g_reading.fd, &g_reading.line);
		if (*g_reading.line == 'R')
			handle_r(g_reading.line);
		else if (*g_reading.line == 'N')
			handle_no(g_reading.line);
		else if (*g_reading.line == 'S' && *(g_reading.line + 1) == 'O')
			handle_so(g_reading.line);
		else if (*g_reading.line == 'W')
			handle_we(g_reading.line);
		else if (*g_reading.line == 'E')
			handle_ea(g_reading.line);
		else if (*g_reading.line == 'S' && *(g_reading.line + 1) != 'O')
			handle_s(g_reading.line);
		else if (*g_reading.line == 'F')
			handle_f(g_reading.line);
		else if (*g_reading.line == 'C')
			handle_c(g_reading.line);
		else if (*g_reading.line == '\0')
			continue;
		else
			handle_map(g_reading.line);
	}
	close(g_reading.fd);
	g_reading.fd = open("./map.cub", O_RDONLY);
	g_reading.sec_read = 1;
	g_reading.other_map = (char **)malloc(sizeof(char *) * g_reading.map_height + 2);
	g_reading.read = 1;
	while (g_reading.read)
	{
		g_reading.read = get_next_line(g_reading.fd, &g_reading.line);
		if (*g_reading.line == 'R' || *g_reading.line == 'N' || *g_reading.line == 'S'
			|| *g_reading.line == 'W' || *g_reading.line == 'E' || *g_reading.line == 'F'
			|| *g_reading.line == 'C' || *g_reading.line == '\0')
			continue;
		else
			handle_map(g_reading.line);
	}
	*(g_reading.other_map + g_reading.i) = NULL;
}