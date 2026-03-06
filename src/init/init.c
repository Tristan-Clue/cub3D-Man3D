/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:19:22 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/06 17:27:38 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <stdio.h>

int	init_mlx(t_data *data)
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

static void	set_vector(t_vec *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
}

void	init_player_dir(t_player *player, t_map *map)
{
	player->pos.x = map->starting_pos.x + 0.5;
	player->pos.y = map->starting_pos.y + 0.5;
	if (map->starting_dir == NORTH)
	{
		set_vector(&player->plane, 0.88, 0);
		set_vector(&player->dir, 0, -1);
	}
	if (map->starting_dir == EAST)
	{
		set_vector(&player->plane, 0, 0.88);
		set_vector(&player->dir, 1, 0);
	}
	if (map->starting_dir == SOUTH)
	{
		set_vector(&player->plane, -0.88, 0);
		set_vector(&player->dir, 0, 1);
	}
	if (map->starting_dir == WEST)
	{
		set_vector(&player->plane, 0, 0.88);
		set_vector(&player->dir, -1, 0);
	}
}
