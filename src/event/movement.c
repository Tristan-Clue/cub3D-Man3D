/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:20:39 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/16 13:43:40 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdio.h>

int	collide_y(double x, t_player *player, t_map *map);
int	collide_x(double y, t_player *player, t_map *map);
int	check_x(double x, t_player *player, t_map *map);
int	check_y(double y, t_player *player, t_map *map);

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
	return (movement);
}

t_vec	get_avg_movement(t_input *input, t_vec movement)
{
	if (input->movement == (KEY_W | KEY_A)
		|| input->movement == (KEY_W | KEY_D)
		|| input->movement == (KEY_S | KEY_A)
		|| input->movement == (KEY_S | KEY_D))
	{
		movement.x /= 2;
		movement.y /= 2;
	}
	return (movement);
}

// TODO: Start from the base of walking side ways and hitting a corner
// diagonal
void	handle_movement(t_input *input, t_player *player, t_map *map)
{
	t_vec	movement;
	t_vec	new;

	if (input->movement & KEY_W || input->movement & KEY_A
		|| input->movement & KEY_S || input->movement & KEY_D)
	{
		movement = combine_movement(input, player);
		movement = get_avg_movement(input, movement);
		new.x = player->pos.x + movement.x;
		new.y = player->pos.y + movement.y;
		if (check_x(new.x, player, map))
			player->pos.x = new.x;
		if (check_y(new.y, player, map))
			player->pos.y = new.y;
	}
}
