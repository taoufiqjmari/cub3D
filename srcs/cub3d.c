/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:43:56 by tjmari            #+#    #+#             */
/*   Updated: 2021/01/19 19:22:24 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	setup(void)
{
	if (!(g_mlx.mlx = mlx_init()))
		my_exit(2);
	if (!(g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, g_mlx.win_width,
											g_mlx.win_height, "cub3D")))
		my_exit(3);
	if (!(g_mlx.img = mlx_new_image(g_mlx.mlx,
										g_mlx.win_width, g_mlx.win_height)))
		my_exit(4);
	g_mlx.addr = mlx_get_data_addr(g_mlx.img, &g_mlx.bits_per_pixel,
										&g_mlx.line_length, &g_mlx.endian);
	g_ply.player_defined = 0;
	g_ply.turn_direction = 0;
	g_ply.walk_direction = 0;
	g_ply.move_speed = 10.0;
	g_ply.rotation_speed = rad(5);
	g_distance_proj_plane = (g_mlx.win_width / 2) / tan(FOV_ANG / 1.5);
	textures();
}

void	render(void)
{
	update_player();
	update_rays();
	render_3d();
	render_map();
	render_rays();
	render_player();
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_mlx.img, 0, 0);
}

int		main(void)
{
	reading_file();
	final_map();
	setup();
	render_map();
	render();
	mlx_hook(g_mlx.mlx_win, 2, 1L << 0, key_pressed, &g_ply);
	mlx_hook(g_mlx.mlx_win, 17, 0L, red_cross, &g_mlx);
	mlx_loop(g_mlx.mlx);
	return (EXIT_SUCCESS);
}
