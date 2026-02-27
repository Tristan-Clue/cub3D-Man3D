/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:25:28 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/27 14:49:43 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

/*
 * NOTE:
** Convert an xpm file to a new image instance.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	char *filename	the file to load;
** @param	int  *width		a pointer to where the width ought to be written;
** @param	int  *height	a pointer to where the height ought to be written;
** @return	void*			the image instance, and NULL in case of error.
*/
// NOTE: void	*mlx_xpm_file_to_image(void *mlx_ptr,
// 				char *filename, int *width, int *height);
// 		Function will put the texture into a new image pointer.


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

int	assign_tx_path(void *mlx, t_map *map)
{
	map->tx[0].img.img_ptr = mlx_xpm_file_to_image(mlx,
					map->tx_path[0], &map->tx[0].width, &map->tx[0].height);
	map->tx[1].img.img_ptr = mlx_xpm_file_to_image(mlx,
					map->tx_path[1], &map->tx[1].width, &map->tx[1].height);
	map->tx[2].img.img_ptr = mlx_xpm_file_to_image(mlx,
					map->tx_path[2], &map->tx[2].width, &map->tx[2].height);
	map->tx[3].img.img_ptr = mlx_xpm_file_to_image(mlx,
					map->tx_path[3], &map->tx[3].width, &map->tx[3].height);
	if (!map->tx[0].img.img_ptr || !map->tx[1].img.img_ptr
	 || !map->tx[2].img.img_ptr || !map->tx[3].img.img_ptr)
	{
		delete_tx_img(mlx, map);
		return (FAILURE);
	}
	// HACK: Texture path no longer in use after extracting xpm
	return (SUCCESS);
}
