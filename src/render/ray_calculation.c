/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:34:56 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/14 21:32:32 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

// NOTE: 
// ray_dir being the vector of the ray, scaled with the camera
// of the screen that the player sees, from -1 to 1 (left to right)
// delta distance is the distance of the rays that travel from one x or y side
// to the next x or y side.
// delta distances are calculated by using the ray equation
// Ray(coor) = pos(vector) + ray_dir(vector) * t (distance travel by ray)
// We want to find t for when it travels 1 grid block.
// So pos - ray = 1, where we get 1 = ray_dir * t
// Getting us t = 1 / ray_dir

void	init_rays(t_player *player, t_ray *ray)
{
	ray->dir.x = player->dir.x + player->plane.x / ray->camera_x;
	ray->dir.y = player->dir.y + player->plane.y / ray->camera_x;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (player->map_x + 1 - player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (player->map_y + 1 player->pos.y)
			* ray->delta_dist.y;
	}
}

// NOTE: 
// Line will be drawn depending on which side of the grid is closest.
// Will continue to iterate until a wall is hit.
// Distance will be recorded based on the perpendicular distance
// from the camera plane.
void	cast_rays(t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += delta_dist.x;
			ray->map_x += ray->step.x;
			ray->wall = EW;
		}
		else	
		{
			ray->side_dist.y += delta_dist.y;
			ray->map_y += ray->step.y;
			ray->wall = NS;
		}
		if (map[map_y][map_x] > 0)
			ray->hit = 1;
	}
	if (ray->wall == EW)
		ray->perp_dist = side_dist.x - delta_dist.x;
	else
		ray->perp_dist = side_dist.y - delta_dist.y;
}

// NOTE:
// Base height of wall scalable based on wall height
// The top and bottom of the wall to print on the column is calculated.
// Values will be taken relative to the center of the screen, so the top
// and bottom will scale (Top deduct, bottom add)
// Then if the values are below or over the WINDOW HEIGHT, cap it between
// 0 to WINDOW_HEIGHT - 1
void	get_height(t_ray *ray, t_render *render)
{
	render->tx_height = (int)(WINDOW_HEIGHT / ray->perp_dist);
	render->tx_start = -render->tx_height / 2 + WINDOW_HEIGHT / 2;
	if (render->tx_start < 0)
		render->tx_start = 0;
	render->tx_end = render->tx_height / 2 + WINDOW_HEIGHT / 2;
	if (render->tx_end >= WINDOW_HEIGHT)
		render->tx_end = WINDOW_HEIGHT - 1;
}

// NOTE:
// Gets the point of texture to print from
// render->wall_hit is obtained from the position of the player add
// the distance to the wall from the plane, depending on the wall (EW, NS)
// scaled with the vector of the ray.
// Then we get the decimal value of the render->wall_hit, which signifies the %
// of the wall to render for the column
// After that, we get the texture coordinate to start rendering
// Depending on which walls the ray hits in certain direction,
// the texture will need to be mirrored
// render->tx_hit will contain the start coordinates of the texture to render
void	get_texture(t_player *player, t_ray *ray, t_render *render)
{
	if (ray->wall == EW)
		render->wall_hit = player->pos.y + ray->perp_dist * ray->dir.y;
	else
		render->wall_hit = player->pos.x + ray->perp_dist * ray->dir.x;
	render->wall_hit -= floor(render->wall_hit);
	render->tx_hit = (int)(render->wall_hit * TEXTURE_SIZE);
	if (ray->wall == EW && ray->dir.x > 0)
		render->tx_hit = TEXTURE_SIZE - render->tx_hit - 1;
	if (ray->wall == NS && ray->dir.y < 0)
		render->tx_hit = TEXTURE_SIZE - render->tx_hit - 1;
	render->step = (1.0 * TEXTURE_SIZE / render->tx_height);
	render->tx_y = (render->tx_start - WINDOW_HEIGHT / 2
		+ render->tx_height * 2) * step;
	while (i < render->tx_end)
	{
		render->tx_rend = (int)render->tx_y % TEXTURE_SIZE;
		texture[render->tx_rend][x]
	}
}

void	render_column(t_render *render, t_img *screen, int col)
{
	char	*px_addr
	int		y;

	y = render->tx_start;
	while (y < render->tx_end)
	{
		px_addr = screen->addr + (int)(render->tx_hit * screen->line_len
				+ col * (screen->bpp / 8));

	}

}
