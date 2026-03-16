/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:42:46 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/16 13:44:48 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	collide_y(double x, t_player *player, t_map *map)
{
	if (map->layout[(int)floor(player->pos.y + 0.2)]
		[(int)floor(x)] == '1'
		|| map->layout[(int)floor(player->pos.y - 0.2)]
		[(int)floor(x)] == '1')
		return (0);
	if (map->layout[(int)floor(player->pos.y - 0.2)]
		[(int)floor(x)] == '1'
		|| map->layout[(int)floor(player->pos.y + 0.2)]
		[(int)floor(x)] == '1')
		return (0);
	return (1);
}

int	collide_x(double y, t_player *player, t_map *map)
{
	if (map->layout[(int)floor(y)]
		[(int)floor(player->pos.x + 0.2)] == '1'
		|| map->layout[(int)floor(y)]
		[(int)floor(player->pos.x - 0.2)] == '1')
		return (0);
	if (map->layout[(int)floor(y)]
		[(int)floor(player->pos.x - 0.2)] == '1'
		|| map->layout[(int)floor(y)]
		[(int)floor(player->pos.x + 0.2)] == '1')
		return (0);
	return (1);
}

int	check_x(double x, t_player *player, t_map *map)
{
	if (map->layout[(int)floor(player->pos.y)]
		[(int)floor(x + 0.2)] == '1'
		|| !collide_y(x + 0.2, player, map))
		return (0);
	if (map->layout[(int)floor(player->pos.y)]
		[(int)floor(x - 0.2)] == '1'
		|| !collide_y(x - 0.2, player, map))
		return (0);
	if (map->layout[(int)floor(player->pos.y)]
		[(int)floor(x - 0.2)] == '1'
		|| !collide_y(x - 0.2, player, map))
		return (0);
	if (map->layout[(int)floor(player->pos.y)]
		[(int)floor(x + 0.2)] == '1'
		|| !collide_y(x + 0.2, player, map))
		return (0);
	return (1);
}

int	check_y(double y, t_player *player, t_map *map)
{
	if (map->layout[(int)floor(y + 0.2)]
		[(int)floor(player->pos.x)] == '1'
		|| !collide_x(y + 0.2, player, map))
		return (0);
	if (map->layout [(int)floor(y - 0.2)]
		[(int)floor(player->pos.x)] == '1'
		|| !collide_x(y - 0.2, player, map))
		return (0);
	if (map->layout[(int)floor(y - 0.2)]
		[(int)floor(player->pos.x)] == '1'
		|| !collide_x(y - 0.2, player, map))
		return (0);
	if (map->layout[(int)floor(y + 0.2)]
		[(int)floor(player->pos.x)] == '1'
		|| !collide_x(y + 0.2, player, map))
		return (0);
	return (1);
}
