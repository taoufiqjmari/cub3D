/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:28:56 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 19:02:58 by tjmari           ###   ########.fr       */
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
	g_elements.temp_map = ft_strdup("");
	g_elements.map_width = 0;
	g_elements.map_height = 0;
	g_ply.player_defined = 0;
	g_sprite.count = 0;
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
			if (*part++ == ',')
				commas++;
		}
		if (commas != 2)
			my_exit("Error in file");
	}
}

void	free_dpointer(char **str)
{
	int		i;

	if (str)
	{
		i = how_many_part(str);
		while (i >= 0)
		{
			free(str[i]);
			str[i] = NULL;
			i--;
		}
		free(str);
	}
	str = NULL;
}
