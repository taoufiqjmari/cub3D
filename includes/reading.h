/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:42:03 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/27 16:52:29 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "cub3d.h"

# define BUFFER_SIZE 100

typedef struct	s_elements
{
	int			fd;
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

void			reading_file(void);
void			init_elements(void);
int				get_next_line(int fd, char **line);
void			validate_r(char *line);
void			validate_no(char *line);
void			validate_so(char *line);
void			validate_we(char *line);
void			validate_ea(char *line);
void			validate_s(char *line);
void			validate_f(char *line);
void			validate_c(char *line);
int				create_trgb(int r, int g, int b);
void			is_info_correct(char *part, char c);
int				how_many_part(char **part);
void			all_read(void);
void			final_map(void);
void			map_parsing(void);
void			to_check(size_t i, size_t j);
int				splitted_to(char **str);
void			free_dpointer(char **str, int i);

#endif
