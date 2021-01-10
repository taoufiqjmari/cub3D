/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:01:56 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/10 10:45:37 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		gnl_put(char **s, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		temp = ft_substr(*s, i + 1, ft_strlen(*s));
		free(*s);
		*s = temp;
		return (1);
	}
	else
	{
		*line = ft_substr(*s, 0, i);
		free(*s);
		*s = NULL;
		return (0);
	}
}

int		gnl_read(int fd, char **s, char **line)
{
	int		i;
	char	*s2;
	char	*temp;

	if (!(s2 = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((i = read(fd, s2, BUFFER_SIZE)) > 0)
	{
		s2[i] = '\0';
		if (!*s)
			*s = ft_substr("", 0, 0);
		temp = ft_strjoin(*s, s2);
		free(*s);
		*s = temp;
		if (ft_strchr(*s, '\n'))
		{
			free(s2);
			s2 = NULL;
			return (gnl_put(s, line));
		}
	}
	if (i == -1)
	{
		free(s2);
		s2 = NULL;
		return (i);
	}
	else if (!*s && i == 0)
	{
		*line = ft_substr("", 0, 0);
		free(s2);
		s2 = NULL;
		return (i);
	}
	else
	{
		free(s2);
		s2 = NULL;
		return (gnl_put(s, line));
	}
}

int		get_next_line(int fd, char **line)
{
	static char *str;

	if (str && ft_strchr(str, '\n'))
		return (gnl_put(&str, line));
	else
		return (gnl_read(fd, &str, line));
}
