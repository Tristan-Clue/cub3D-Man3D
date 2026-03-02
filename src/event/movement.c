/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:20:39 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/02 13:50:17 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	movement_w(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = floor(player->pos.x + player->dir.x * MOVE_SPEED);
	y = floor(player->pos.y + player->dir.y * MOVE_SPEED);
	if (map->layout[player->pos.y][x] != 1)
		player->pos.x = x;
	if (map->layout[y][player->pos.x] != 1)
		player->pos.y = y;
}

static void	movement_s(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = floor(player->pos.x - player->dir.x * MOVE_SPEED);
	y = floor(player->pos.y - player->dir.y * MOVE_SPEED);
	if (map->layout[player->pos.y][x] != 1)
		player->pos.x = x;
	if (map->layout[y][player->pos.x] != 1)
		player->pos.y = y;
}

static void	movement_a(t_player *player, t_map *map)
{
	int	x;
	int	y;
	x = floor(player->pos.x + player->plane.x * MOVE_SPEED);
	y = floor(player->pos.y + player->plane.y * MOVE_SPEED);
	if (map->layout[player->pos.y][x] != 1)
		player->pos.x = x;
	if (map->layout[y][player->pos.x] != 1)
		player->pos.y = y;
}

static void	movement_d(t_player *player, t_map *map)
{
	int	x;
	int	y;

	x = floor(player->pos.x - player->plane.x * MOVE_SPEED);
	y = floor(player->pos.y - player->plane.y * MOVE_SPEED);
	if (map->layout[player->pos.y][x] != 1)
		player->pos.x = x;
	if (map->layout[y][player->pos.x] != 1)
		player->pos.y = y;
}
void	handle_movement(t_input *input, t_player *player, t_map *map)
{
	if (input->movement & KEY_W)
		movement_w(player, map);
	if (input->movement & KEY_S)
		movement_s(player, map);
	if (input->movement & KEY_A)
		movement_a(player, map);
	if (input->movement & KEY_D)
		movement_d(player, map);
}
