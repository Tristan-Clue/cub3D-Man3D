/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:58:44 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/10 12:22:29 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "render.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_map_info(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	printf("Map Layout (Row: %d, Col: %d):\n", map->row_number,
		map->col_number);
	while (++y < map->row_number)
	{
		x = -1;
		while (++x < map->col_number)
			printf("%c", map->layout[y][x]);
		printf("\n");
	}
	printf("Ceiling : %X\nFloor: %X\n", map->ceiling_color, map->floor_color);
	printf("Player Starting pos: %f, %f\n", map->starting_pos.x,
		map->starting_pos.y);
	printf("Player Starting direction: %d\n", map->starting_dir);
}

void	print_tex_info(t_map *map)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		printf("Tex%d ptr: %p, ", x + 1, map->tx[x].img.img_ptr);
		printf("Px: %p, bpp: %d, ", map->tx[x].img.px, map->tx[x].img.bpp);
		printf("len: %d, endian: %d\n", map->tx[x].img.line_len,
			map->tx[x].img.endian);
		x++;
	}
}

void	print_player_info(t_player *player)
{
	printf("Player pos: %lf, %lf\n", player->pos.x, player->pos.y);
	printf("Player dir: %lf, %lf\n", player->dir.x, player->dir.y);
	printf("Player plane: %lf, %lf\n", player->plane.x, player->plane.y);
}
