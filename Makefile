# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 20:17:40 by tjmari            #+#    #+#              #
#    Updated: 2020/10/26 18:35:39 by tjmari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

SEARCH_PATH = -I /usr/local/include

LIB = -L /usr/local/lib -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = cub3D.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SEARCH_PATH) $(SRC) $(LIB) $(FRAMEWORKS) -o $(NAME) && ./cub3D
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fcean all