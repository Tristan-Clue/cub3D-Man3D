/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:53:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/12 17:03:50 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include <stdio.h>

static void	prep_col(t_anim *obj)
{
	obj->pos.x = (obj->curr.frames % obj->col) * obj->sprite_width;
	obj->tex_y = (int)obj->pos.y % obj->height;
	obj->pos.y += obj->step;
}

static void	prep_row(t_anim *obj)
{
	obj->tex_x = (int)obj->pos.x % obj->width;
	obj->pos.x += obj->step;
}

static char	*set_color(t_anim *obj)
{
	return (obj->img.px + (obj->tex_y) * obj->img.line_len
		+ (obj->tex_x) * (obj->img.bpp / 8));
}

void	render_anim(t_anim *obj, t_img *screen, int start_x, int start_y)
{
	char	*color;
	char	*px;
	int		y;
	int		x;

	y = 0;
	obj->pos.y = (obj->curr.frames / obj->col) * obj->sprite_height;
	while (start_y + y < WINDOW_HEIGHT && y < obj->sprite_height * obj->scale)
	{
		prep_col(obj);
		x = 0;
		while (start_x + x < WINDOW_WIDTH && x < obj->sprite_width * obj->scale)
		{
			prep_row(obj);
			color = set_color(obj);
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
