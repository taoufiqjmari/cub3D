# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 20:17:40 by tjmari            #+#    #+#              #
#    Updated: 2020/12/25 09:58:37 by tjmari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror

SEARCH_PATH = -I /usr/local/include

LIB = -L /usr/local/lib -lmlx

FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = ./srcs/cub3d.c ./srcs/map.c ./srcs/player.c ./srcs/rays.c \
./srcs/sprite.c ./srcs/draw.c ./srcs/angles.c ./srcs/three_d.c ./srcs/exit.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft_lib
	@gcc $(FLAGS) $(SEARCH_PATH) $(SRC) $(LIB) $(FRAMEWORKS) $(LIBFT) -o $(NAME)
	@echo "\033[1;32mCUB3D: ./$(NAME) made\n-------------------"

libft_lib:
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "\033[1;32mCUB3D: ./$(LIBFT) moved to $(NAME)\n-------------------------------"

clean:
	@make clean -C ./libft

fclean: clean
	@rm -f $(LIBFT)
	@echo "\033[1;31mCUB3D: ./$(LIBFT) deleted\n------------------------"
	@rm -f $(NAME)
	@echo "\033[1;31mCUB3D: ./$(NAME) deleted\n----------------------"

re: fclean all

run: re
	@./cub3D
	@rm $(NAME)
	@echo "\033[1;32m----------------------\n\033[1;31mCUB3D: ./$(NAME) deleted\n----------------------"
