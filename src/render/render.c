/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:58:17 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/02 17:46:32 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>
#include <stdio.h>

// NOTE: Renders the image the player looks at.
// Background is rendered to the image address first to simplify process.
// Img is then split into columns for ray casting, to render the wall
// based off the distance through the DDA algorithm.
// Once the distance is calculated, the height of the wall is determined
// and the size of the wall will be calculated to determine how much of the
// texture will be rendered in that column.


void	render_pov(t_img *screen, t_player *player, t_map *map)
{
	int			col;
	t_ray		ray;
	t_render	render;

	col = 0;
	render_background(screen, map);
	while (col < WINDOW_WIDTH)
	{
		ray = (t_ray){0};
		render = (t_render){0};
		ray.map_x = floor(player->pos.x);
		ray.map_y = floor(player->pos.y);
		ray.hit = 0;
		ray.camera_x = 2.0 * ((double)col / WINDOW_WIDTH) - 1.0;
		init_rays(player, &ray);	// Initiate current column ray
		cast_rays(&ray, map);
		get_height(&ray, &render);
		get_texture(player, &ray, &render);
		render_column(&render, screen, map, col);
		col++;
	}
}
