/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:20:39 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/06 15:05:43 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

static void	movement_w(t_player *player, t_map *map)
{
	double	x;
	double	y;

	x = player->pos.x + player->dir.x * MOVE_SPEED;
	y = player->pos.y + player->dir.y * MOVE_SPEED;
	if (player->dir.x && map->layout
		[(int)floor(player->pos.y)]
		[(int)floor(x + (player->dir.x / fabs(player->dir.x)) * 0.2)] != '1')
		player->pos.x = x;
	if (player->dir.y && map->layout
		[(int)floor(y + (player->dir.y / fabs(player->dir.y)) * 0.2)]
		[(int)floor(player->pos.x)] != '1')
		player->pos.y = y;
}

static void	movement_s(t_player *player, t_map *map)
{
	double	x;
	double	y;

	x = player->pos.x - player->dir.x * MOVE_SPEED;
	y = player->pos.y - player->dir.y * MOVE_SPEED;
	if (player->dir.x && map->layout
		[(int)floor(player->pos.y)]
		[(int)floor(x - (player->dir.x / fabs(player->dir.x)) * 0.2)] != '1')
		player->pos.x = x;
	if (player->dir.y && map->layout
		[(int)floor(y - (player->dir.y / fabs(player->dir.y)) * 0.2)]
		[(int)floor(player->pos.x)] != '1')
		player->pos.y = y;
}

static void	movement_a(t_player *player, t_map *map)
{
	double	x;
	double	y;
	x = player->pos.x - player->plane.x * MOVE_SPEED;
	y = player->pos.y - player->plane.y * MOVE_SPEED;
	if (player->plane.x && map->layout
		[(int)floor(player->pos.y)]
		[(int)floor(x - (player->plane.x / fabs(player->plane.x)) * 0.2)] != '1')
		player->pos.x = x;
	if (player->plane.y && map->layout
		[(int)floor(y - (player->plane.y / fabs(player->plane.y))* 0.2)]
		[(int)floor(player->pos.x)] != '1')
		player->pos.y = y;
}

static void	movement_d(t_player *player, t_map *map)
{
	double	x;
	double	y;

	x = player->pos.x + player->plane.x * MOVE_SPEED;
	y = player->pos.y + player->plane.y * MOVE_SPEED;
	if (player->plane.x && map->layout
		[(int)floor(player->pos.y)]
		[(int)floor(x + (player->plane.x / fabs(player->plane.x)) * 0.2)] != '1')
		player->pos.x = x;
	if (player->plane.y && map->layout
		[(int)floor(y + (player->plane.y / fabs(player->plane.y)) * 0.2)]
		[(int)floor(player->pos.x)] != '1')
		player->pos.y = y;
}

int	diagonal_movement(int movement)
{
	if (movement & KEY_W && (movement & KEY_D || movement & KEY_A))
	{
		//printf("diagonal up\n");
		return (1);
	}
	if (movement & KEY_S && (movement & KEY_D || movement & KEY_A))
	{
		//printf("diagonal down\n");
		return (1);
	}
	return (0);
}

void	handle_movement(t_input *input, t_player *player, t_map *map)
{
//	if (diagonal_movement(input->movement))
//		perform_diagonal(input, player, map);
	if (input->movement & KEY_W)
		movement_w(player, map);
	if (input->movement & KEY_S)
		movement_s(player, map);
	if (input->movement & KEY_A)
		movement_a(player, map);
	if (input->movement & KEY_D)
		movement_d(player, map);
}
