# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 20:17:40 by tjmari            #+#    #+#              #
#    Updated: 2020/12/27 19:15:37 by tjmari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
ORANGE = \033[1;33m

NAME = cub3D
LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror
SEARCH_PATH = -I /usr/local/include
LIB = -L /usr/local/lib -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit

SRC = ./srcs/cub3d.c ./srcs/reading.c ./srcs/get_next_line.c ./srcs/map.c ./srcs/player.c \
./srcs/rays.c ./srcs/sprite.c ./srcs/draw.c ./srcs/angles.c ./srcs/three_d.c ./srcs/exit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft_lib
	@gcc $(FLAGS) $(SEARCH_PATH) $(SRC) $(LIB) $(FRAMEWORKS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)CUB3D: ./$(NAME) made\n-------------------$(NC)"

libft_lib:
	@make -C ./libft
	@mv ./libft/$(LIBFT) ./
	@echo "$(GREEN)CUB3D: ./$(LIBFT) moved to $(NAME)\n-------------------------------$(NC)"

clean:
	@make clean -C ./libft

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)CUB3D: ./$(LIBFT) deleted\n------------------------$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)CUB3D: ./$(NAME) deleted\n----------------------$(NC)"

re: fclean all

run: re
	@./cub3D