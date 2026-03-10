/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:19:22 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/10 21:01:04 by mjoon-yu         ###   ########.fr       */
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
	mlx_mouse_hide(data->mlx, data->window);
	return (SUCCESS);
}

int	init_lanturn(void *mlx, t_anim *obj)
{
	obj->img.img_ptr = mlx_xpm_file_to_image(mlx, LANTURN_PATH,
			&obj->width, &obj->height);
	if (!obj->img.img_ptr)
		return (FAILURE);
	obj->img.px = mlx_get_data_addr(obj->img.img_ptr, &obj->img.bpp,
			&obj->img.line_len, &obj->img.endian);
	if (!obj->img.px)
	{
		mlx_destroy_image(mlx, obj->img.img_ptr);
		return (FAILURE);
	}
	obj->frames = 21;// ENTER FRAMES HERE
	obj->sprite_width = 30; // ENTER WIDTH OF EACH FRAME IN PX
	obj->sprite_height = 45; // HEIGHT OF EACH FRAME IN PX
	obj->col = 7; // NUMBER OF FRAMES PER ROW
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
