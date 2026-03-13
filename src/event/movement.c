/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:20:39 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/13 21:23:40 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

double	get_sign(double i)
{
	if (i > 0)
		return (1);
	if (i < 0)
		return (-1);
	return (0);
}

int	check_x(double x, t_player *player, t_map *map)
{
	if (map->layout[(int)floor(player->pos.y)]
		[(int)floor(x + get_sign(player->dir.x) * 0.2)] == '1'
			|| map->layout[(int)floor(player->pos.y)]
			[(int)floor(x - get_sign(player->dir.x) * 0.2)] == '1')
			return (0);
		if (map->layout[(int)floor(player->pos.y)]
			[(int)floor(x - get_sign(player->plane.x) * 0.2)] == '1'
			|| map->layout[(int)floor(player->pos.y)]
			[(int)floor(x + get_sign(player->plane.x) * 0.2)] == '1')
			return (0);
	return (1);
}

int	check_y(double y, t_player *player, t_map *map)
{
		if (map->layout[(int)floor(y + get_sign(player->dir.y) * 0.2)]
			[(int)floor(player->pos.x)] == '1' || map->layout
			[(int)floor(y - get_sign(player->dir.y) * 0.2)]
			[(int)floor(player->pos.x)] == '1')
			return (0);
		if (map->layout
			[(int)floor(y - get_sign(player->plane.y) * 0.2)]
			[(int)floor(player->pos.x)] == '1'
			|| map->layout
			[(int)floor(y + get_sign(player->plane.y) * 0.2)]
			[(int)floor(player->pos.x)] == '1')
			return (0);
	return (1);
}

int	collide_y(double x, t_player *player, t_map *map)
{
		if (map->layout[(int)floor(player->pos.y + get_sign(player->dir.y) * 0.2)]
			[(int)floor(x)] == '1'
			|| map->layout[(int)floor(player->pos.y - get_sign(player->dir.y) * 0.2)]
			[(int)floor(x)] == '1')
			return (0);
		if (map->layout[(int)floor(player->pos.y - get_sign(player->plane.y) * 0.2)]
			[(int)floor(x)] == '1'
			|| map->layout[(int)floor(player->pos.y + get_sign(player->plane.y * 0.2))]
			[(int)floor(x)] == '1')
			return (0);
	return (1);
}

int	collide_x(double y, t_player *player, t_map *map)
{
		if (map->layout[(int)floor(y)]
			[(int)floor(player->pos.x + get_sign(player->dir.x) * 0.2)] == '1'
			|| map->layout[(int)floor(y)]
			[(int)floor(player->pos.x - get_sign(player->dir.x) * 0.2)] == '1')
			return (0);
		if(map->layout[(int)floor(y)]
			[(int)floor(player->pos.x - get_sign(player->plane.x) * 0.2)] == '1'
			|| map->layout[(int)floor(y)]
			[(int)floor(player->pos.x + get_sign(player->plane.x) * 0.2)] == '1')
			return (0);
	return (1);
}
t_vec	combine_movement(t_input *input, t_player *player)
{
	t_vec	movement;

	movement = (t_vec){0};
	if (input->movement & KEY_W)
	{
		movement.x += player->dir.x * MOVE_SPEED;
		movement.y += player->dir.y * MOVE_SPEED;
	}
	if (input->movement & KEY_S)
	{
		movement.x += -player->dir.x * MOVE_SPEED;
		movement.y += -player->dir.y * MOVE_SPEED;
	}
	if (input->movement & KEY_A)
	{
		movement.x += -player->plane.x * MOVE_SPEED;
		movement.y += -player->plane.y * MOVE_SPEED;
	}
	if (input->movement & KEY_D)
	{
		movement.x += player->plane.x * MOVE_SPEED;
		movement.y += player->plane.y * MOVE_SPEED;
	}
	if (input->movement == (KEY_W | KEY_A) || input->movement == (KEY_W | KEY_D)
	 || input->movement == (KEY_S | KEY_A) || input->movement == (KEY_S | KEY_D))
	{
		movement.x /= 2;
		movement.y /= 2;
	}
	return (movement);
}

void	handle_movement(t_input *input, t_player *player, t_map *map)
{
	t_vec	movement;
	t_vec	new;
	int		check = 0;
	if (input->movement & KEY_W || input->movement & KEY_A 
		|| input->movement & KEY_S || input->movement & KEY_D)
	{
		movement = combine_movement(input, player);
		new.x = player->pos.x + movement.x;
		new.y = player->pos.y + movement.y;
		if (check_x(new.x, player, map) && collide_y(new.x, player, map))
		{
			check = 1;
			player->pos.x = new.x;
		}
		if (check_y(new.y, player, map) && collide_x(new.y, player, map))
		{
			check = 1;
			player->pos.y = new.y;
		}
		if (check == 1)
			printf("New player coor: %f, %f\n", player->pos.x, player->pos.y);
	}
}
