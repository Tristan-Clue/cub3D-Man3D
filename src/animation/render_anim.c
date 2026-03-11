/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/11 16:28:01 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

void	assign_upscale(t_data *data, int start_x, int start_y, int scale, char *color)
{
	int		x;
	int		y;
	char	*px;

	y = 0;
	while (start_y + y < WINDOW_HEIGHT && y < scale)
	{
		x = 0;
		while (start_x + x < WINDOW_WIDTH && x < scale)
		{
			px = data->img.px + ((start_y + y) * data->img.line_len)
				+ ((start_x + x) * (data->img.bpp / 8));
			*(unsigned int *)px = *(unsigned int *)color;
			x++;
		}
		y++;
	}
}

void	render_anim(t_data *data, int start_x, int start_y)
{
	char	*color;
	int		y;
	int		x;
	int		frame;

	y = 0;
	frame = data->frames.frames % data->obj.frames;
	while (start_y + y < WINDOW_HEIGHT && y < data->obj.sprite_height)
	{
		x = 0;
		while (start_x + x < WINDOW_WIDTH && x < data->obj.sprite_width)
		{
			color = data->obj.img.px + (((frame / data->obj.col)
						* data->obj.sprite_height + y) * data->obj.img.line_len)
				+ ((frame % data->obj.col)
				* data->obj.sprite_width + x) * (data->obj.img.bpp / 8);
			if (*(int *)color >= 0)
				assign_upscale(data, start_x + (x * 10), start_y + (y * 10), 10, color);
			x++;
		}
		y++;
	}
}
