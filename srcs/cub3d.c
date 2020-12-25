/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2020/12/25 09:58:56 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		key_pressed(int keycode, t_ply *g_ply)
{
	g_ply->straight = 1;
	if (keycode == CLICK_LEFT)
	{
		g_ply->walk_direction = -1;
		g_ply->straight = 0;
	}
	else if (keycode == CLICK_RIGHT)
	{
		g_ply->walk_direction = +1;
		g_ply->straight = 0;
	}
	else if (keycode == CLICK_DOWN)
		g_ply->walk_direction = -1;
	else if (keycode == CLICK_UP)
		g_ply->walk_direction = +1;
	else if (keycode == CLICK_LEFT_VIEW)
		g_ply->turn_direction = -1;
	else if (keycode == CLICK_RIGHT_VIEW)
		g_ply->turn_direction = +1;
	else if (keycode == CLICK_ESC)
		my_exit(0);
	render();
	return (0);
}

void	setup(void)
{
	if (!(g_mlx.mlx = mlx_init()))
		my_exit(2);
	if (!(g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, WIN_WIDTH,
											WIN_HEIGHT, "cub3D")))
		my_exit(3);
	if (!(g_mlx.img = mlx_new_image(g_mlx.mlx,
										WIN_WIDTH, WIN_HEIGHT)))
		my_exit(4);
	g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,
										&g_mlx.line_length, &g_mlx.endian);
	g_ply.player_defined = 0;
	g_ply.turn_direction = 0;
	g_ply.walk_direction = 0;
	g_ply.move_speed = 10.0;
	g_ply.rotation_speed = rad(5);
}

void	update(void)
{
	update_player();
	update_rays();
}

void	render(void)
{
	update();
	render_3d();
	render_map();
	render_rays();
	render_player();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_mlx.img, 0, 0);
}

int		main(void)
{
	setup();
	render_map();
	render();
	mlx_hook(g_mlx.mlx_win, 2, 1L << 0, key_pressed, &g_ply);
	mlx_hook(g_mlx.mlx_win, 17, 0L, red_cross, &g_mlx);
	mlx_loop(g_mlx.mlx);
	return (EXIT_SUCCESS);
}
