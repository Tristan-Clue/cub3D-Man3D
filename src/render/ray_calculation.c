/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:34:56 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/10 13:37:53 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	init_rays(t_player *player, t_ray *ray)
{
	ray->dir.x = player->dir.x + player->plane.x / ray->camera_x;
	ray->dir.y = player->dir.y + player->plane.y / ray->camera_x;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = player->pos.x - ray->map_x; 
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = player->map_x + 1 - player->pos.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = player->map_y - 1 - player->pos.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = player->pos.y - player->map_y;
	}
}
