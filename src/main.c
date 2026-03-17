/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:56:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/17 19:00:14 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "cub3d.h"

static	void	print_debug(t_data *data)
{
	print_map_info(&data->map);
	print_tex_info(&data->map);
	print_lanturn_info(&data->anim);
	print_player_info(&data->player);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
	if (argc != 2)
		error_exit("Error\n<format = ./cub3D [FILE]>");
	data = (t_data){0};
	parse_map(&data.map, argv[1]);
	if (init_mlx(&data) == FAILURE)
		error_exit("Error\nmlx/window/image creation failure");
	if (assign_tx_path(data.mlx, &data.map) == FAILURE)
	{
		delete_mlx(&data);
		error_exit("Error\nTextures not loaded");
	}
	init_player_dir(&data.player, &data.map);
	init_lanturn(data.mlx, &data.anim);
	if (DEBUG_MODE)
		print_debug(&data);
	event_loop(&data);
	return (delete_mlx(&data), EXIT_SUCCESS);
}
