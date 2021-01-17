/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:42:03 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/17 18:32:20 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "cub3d.h"

# define BUFFER_SIZE 100

void	reading_file(void);
int		get_next_line(int fd, char **line);
int		gnl_read(int fd, char **s, char **line, int i);
int		gnl_put(char **s, char **line);
int		gnl_return(char *s, int i);

#endif
