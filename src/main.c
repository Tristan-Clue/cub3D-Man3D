/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:56:09 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/02 19:29:54 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/X.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
	if (argc != 2)
		error_exit("Wrong arguments\n<format = ./fdf [FILE]>");
	data = (t_data){0};
	parse_map(&data.map, argv[1]);
	if (init_mlx(&data) == FAILURE)
		error_exit("mlx/window/image creation failure");
	if (assign_tx_path(data.mlx, &data.map) == FAILURE)
	{
		delete_mlx(&data);
		error_exit("Textures not loaded");
	}
	init_player_dir(&data.player, &data.map);
	event_loop(&data);
	return (delete_mlx(&data), EXIT_SUCCESS);
}
