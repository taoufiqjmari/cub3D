#!/bin/sh

# gcc -Wall -Wextra -Werror -I /usr/local/include cub3d.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
gcc -Wall -Wextra -Werror -g -I /usr/local/include cub3d.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# ./a.out