/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:44:39 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/02 17:51:26 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/keysym.h>
#include <math.h>
#include <stdio.h>

static void	rot_mx(t_vec *vec, double angle)
{
	t_vec	vector;

	vector.x = (vec->x * cos(angle * (M_PI / 180)))
		+ (vec->y * sin(angle * (M_PI / 180)));
	vector.y = (vec->x * -sin(angle * (M_PI / 180)))
		+ (vec->y * cos(angle * (M_PI / 180)));
	vec->x = vector.x;
	vec->y = vector.y;
}

void	rotate_camera(t_input *input, t_player *player)
{
	if (input->rotation & KEY_LEFT)
	{
		rot_mx(&player->dir, PAN_ANGLE);
		rot_mx(&player->plane, PAN_ANGLE);
	}
	if (input->rotation & KEY_RIGHT)
	{
		rot_mx(&player->dir, -PAN_ANGLE);
		rot_mx(&player->plane, -PAN_ANGLE);
	}
	if (input->rot_angle)
	{
		rot_mx(&player->dir, input->rot_angle);
		rot_mx(&player->dir, input->rot_angle);
		input->rot_angle = 0;
	}
}
