/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:42:03 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/19 19:04:49 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "cub3d.h"

# define BUFFER_SIZE 100

typedef struct	s_elements
{
	_Bool		r;
	_Bool		no;
	_Bool		so;
	_Bool		we;
	_Bool		ea;
	_Bool		s;
	_Bool		f;
	_Bool		c;
	_Bool		read;
	_Bool		start_map;
	char		*temp_map;
	char		**map_splitted;
	char		**map;
	size_t		map_width;
	size_t		map_height;
}				t_elements;
t_elements		g_elements;

void	reading_file(void);
int		get_next_line(int fd, char **line);
void	validate_r(char *line);
void	validate_no(char *line);
void	validate_so(char *line);
void	validate_we(char *line);
void	validate_ea(char *line);
void	validate_s(char *line);
void	validate_f(char *line);
void	validate_c(char *line);
void	final_map(void);

#endif
