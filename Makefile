# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 20:17:40 by tjmari            #+#    #+#              #
#    Updated: 2020/12/01 16:56:06 by tjmari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Wextra -Werror

SEARCH_PATH = -I /usr/local/include

LIB = -L /usr/local/lib -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = cub3d.c draw.c deg_rad.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SEARCH_PATH) $(SRC) $(LIB) $(FRAMEWORKS) -o $(NAME)

debug:
	@gcc $(FLAGS) -g $(SEARCH_PATH) $(SRC) $(LIB) $(FRAMEWORKS) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)*
	@rm -rf .vscode

re: fclean all

run: re
	./cub3D
