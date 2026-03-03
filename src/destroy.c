/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:11:10 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/03 15:16:36 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <mlx.h>

static void	delete_tx_img(void *mlx, t_map *map)
{
	if (map->tx[0].img.img_ptr)
		mlx_destroy_image(mlx, map->tx[0].img.img_ptr);
	if (map->tx[1].img.img_ptr)
		mlx_destroy_image(mlx, map->tx[1].img.img_ptr);
	if (map->tx[2].img.img_ptr)
		mlx_destroy_image(mlx, map->tx[2].img.img_ptr);
	if (map->tx[3].img.img_ptr)
		mlx_destroy_image(mlx, map->tx[3].img.img_ptr);
}

void	delete_mlx(t_data *data)
{
	delete_tx_img(data->mlx, &data->map);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free (data->mlx);
}

int	destroy(t_data *data)
{
	delete_mlx(data);
	exit(SUCCESS);
}
