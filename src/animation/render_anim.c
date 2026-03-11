/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/11 18:46:40 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

/*
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
*/
void	render_anim(t_anim *obj, t_img *screen, int start_x, int start_y)
{
	char	*color;
	char	*px;
	int		y;
	int		x;

	y = 0;
	obj->curr_frame = (obj->curr_frame + 1) % obj->frames;
	obj->pos.y = (obj->curr_frame / obj->col) * obj->sprite_height;
	while (start_y + y < WINDOW_HEIGHT && y < obj->sprite_height * obj->scale)
	{
		x = 0;
		obj->pos.x = (obj->curr_frame % obj->col) * obj->sprite_width;
		obj->tex_y = (int)obj->pos.y % obj->height;
		obj->pos.y += obj->step;
		while (start_x + x < WINDOW_WIDTH && x < obj->sprite_width * obj->scale)
		{
			obj->tex_x = (int)obj->pos.x % obj->width;
			obj->pos.x += obj->step;
			color = obj->img.px
				+ (obj->tex_y) * obj->img.line_len
				+ (obj->tex_x) * (obj->img.bpp / 8);
			if (*(int *)color >= 0)
			{
				px = screen->px + (start_y + y) * screen->line_len
					+ (start_x + x) * (screen->bpp / 8);
				*(unsigned int *)px = *(unsigned int *)color;
			}
			x++;
		}
		y++;
	}
}
