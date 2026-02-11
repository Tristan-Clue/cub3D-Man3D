/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:58:17 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/10 18:36:36 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NOTE: Renders the image the player looks at.
// Background is rendered to the image address first to simplify process.
// Img is then split into columns for ray casting, to render the wall
// based off the distance through the DDA algorithm.
// Once the distance is calculated, the height of the wall is determined
// and the size of the wall will be calculated to determine how much of the
// texture will be rendered in that column.

void	render_pov(t_img *screen, t_player *player, t_map *map)
{
	int		col;
	t_ray	ray;

	col = 0;
	render_background(screen, map);
	ray = (t_ray){0};
	while (col < RESO_WIDTH)
	{

		ray.cameraX = 2 * (col / RESO_WIDTH) - 1;
		init_rays(&ray, player, );	// Initiate current column ray
		calculate_deltas(&ray, player);
		get_step_dir(&ray);
		get_ray_distance(&ray);
		// What do with distance
		// Get perpendicular distance
		// Render wall texture based off distance
		// calculate which part of texture to render
		col++;
	}
}
