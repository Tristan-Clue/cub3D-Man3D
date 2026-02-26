/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:56:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/26 16:54:53 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "cub3d.h"

static int	init_mlx(t_data *data);
//static void	setup_mlx_loop(t_data *data);

void	init_player(t_player *player, char layout[MAX_MAP_SIZE][MAX_MAP_SIZE])
{
	player->pos.x = 3.0;
	player->pos.y = 3.0;
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'N')
	{
		player->plane.x = 0.66;
		player->plane.y = 0;
		player->dir.x = 0;
		player->dir.y = -1;
	}
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'E')
	{
		player->plane.x = 0;
		player->plane.y = 0.66;
		player->dir.x = 1;
		player->dir.y = 0;
	}
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'S')
	{
		player->plane.x = -0.66;
		player->plane.y = 0;
		player->dir.x = 0;
		player->dir.y = 1;
	}
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'W')
	{
		player->plane.x = 0;
		player->plane.y = -0.66;
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
//	if (argc != 2)
//		error_exit("Wrong arguments\n<format = ./fdf [FILE]>");
	data = (t_data){.map.layout ={{1, 1, 1, 1, 1, 1, 1},
					{1, 1, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 'S', 0, 0, 1},
					{1, 0, 1, 0, 1, 0, 1},
					{1, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1}}};
	//parse_map(&data.map, argv[1]);
	if (init_mlx(&data) == FAILURE)
	{
		//destroy_map(data.map);
		error_exit("mlx/window/image creation failure");
	}

	/*  TODO: for parsing
	 * load_textures;
	 */

	/*
	 * WIP:	calculate_fov();
	 * 		render_columns();
	 *
	 */

	/*  TODO: for execute
	 * setup_mlx_loop(&data); // look below
	 */
	init_player(&data.player, data.map.layout);
	event_loop(&data);
	return (delete_mlx(&data), EXIT_SUCCESS);
}

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (delete_mlx(data), FAILURE);
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, TITLE);
	if (!data->window)
		return (delete_mlx(data), FAILURE);
	data->img.img_ptr = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.img_ptr)
		return (delete_mlx(data), FAILURE);
	data->img.px = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	if (!data->img.px)
	{
		delete_mlx(data);
		error_exit("mlx_get_data_addr failure");
	}
	return (SUCCESS);
}

/*
 *  NOTE: OLD mlx loop setup from fdf
 *
static void	setup_mlx_loop(t_data *data)
{
	print_first_message();
	mlx_loop_hook(data->mlx, &handle_idle, data);
	mlx_expose_hook(data->window, &handle_idle, data);
	mlx_hook(data->window, KeyPress, KeyPressMask,
		&handle_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, data);
	mlx_hook(data->window, ButtonPress, ButtonPressMask,
		&handle_mousepress, data);
	mlx_hook(data->window, ButtonRelease, ButtonReleaseMask,
		&handle_mouserelease, data);
	mlx_hook(data->window, MotionNotify, Button1MotionMask,
		&handle_mouse1drag, data);
	mlx_hook(data->window, DestroyNotify, 0,
		&handle_destroykey, data);
	mlx_loop(data->mlx);
	return ;
}
*/
