/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:19:22 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/27 13:36:20 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

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

void	init_player(t_player *player, char layout[MAX_MAP_SIZE][MAX_MAP_SIZE])
{
	set_vector(&player->pos, 3.5, 3.5);
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'N')
	{
		set_vector(&player->plane, 0.66, 0);
		set_vector(&player->dir, 0, -1);
	}
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'E')
	{
		set_vector(&player->plane, 0, 0.66);
		set_vector(&player->dir, 1, 0);
	}
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'S')
	{
		set_vector(&player->plane, -0.66, 0);
		set_vector(&player->dir, 0, 1);
	}
	if (layout[(int)player->pos.y][(int)player->pos.x] == 'W')
	{
		set_vector(&player->plane, 0, 0.66);
		set_vector(&player->dir, -1, 0);
	}
}
