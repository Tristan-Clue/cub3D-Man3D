/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:24:43 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/23 22:26:25 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// NOTE:
// If upscaling is done, change WINDOW size macros to RESOLUTION macros

void	render_background(t_img *screen, t_map *map)
{
	int		x;
	int		y;
	char	*pixel;

	(void)map;	// To be removed when background color is given
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixel = screen->px + (y * screen->line_len) + x * (screen->bpp / 8);
			if (y < WINDOW_HEIGHT / 2)
				*(unsigned int *)pixel = PIXEL_RED;
				// *(unsigned int *)pixel = map->ceiling;
			else
				*(unsigned int *)pixel = PIXEL_BLUE;
				// *(unsinged int *)pixel = map->floor;
			x++;
		}
		y++;
	}
}
