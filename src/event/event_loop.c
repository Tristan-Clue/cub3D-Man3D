/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:01:11 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/12 16:54:04 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

static void	clamp_frames(t_data *data)
{
	gettimeofday(&data->tv, &data->tz);
	if (data->frames.frames * 33333 < data->tv.tv_usec)
	{
		data->frames.frames++;
		data->flag.render = 1;
	}
	if (data->frames.sec != data->tv.tv_sec)
	{
		data->frames.sec = data->tv.tv_sec;
		printf("FPS: %d\n", data->frames.frames);
		data->frames.frames = 0;
	}
	if (data->anim.curr.sec != data->tv.tv_sec)
	{
		if (data->anim.curr.sec != 0)
			data->anim.curr.frames++;
		data->anim.curr.sec = data->tv.tv_sec;
	}
	else if (((data->anim.curr.frames % data->anim.fps) + 1)
		* (999999 / data->anim.fps) < data->tv.tv_usec)
		data->anim.curr.frames++;
	if (data->anim.curr.frames == data->anim.frames)
		data->anim.curr.frames = 0;
}

static int	handle_idle(t_data *data)
{
	if (data->flag.focus == 1)
		clamp_frames(data);
	if (data->flag.focus == 1 && data->flag.render == 1)
	{
		mlx_mouse_move(data->mlx, data->window,
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		update_data(data);
		render_pov(&data->img, &data->player, &data->map);
		render_anim(&data->anim, &data->img, WINDOW_WIDTH * 5 / 7,
			WINDOW_HEIGHT / 2);
		mlx_put_image_to_window(data->mlx, data->window,
			data->img.img_ptr, 0, 0);
		data->flag.render = 0;
	}
	return (SUCCESS);
}

void	event_loop(t_data *data)
{
	detect_input(data);
	mlx_loop_hook(data->mlx, &handle_idle, data);
	mlx_loop(data->mlx);
}
