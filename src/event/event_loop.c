/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:01:11 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/10 12:34:25 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

static void	clamp_frames(t_tv *tv, t_tz *tz, t_framerate *frames, int *render)
{
	gettimeofday(tv, tz);
	if (frames->frames * 33333 < tv->tv_usec)
	{
		frames->frames++;
		*render = 1;
	}
	if (frames->sec != tv->tv_sec)
	{
		frames->sec = tv->tv_sec;
		printf("FPS: %d\n", frames->frames);
		frames->frames = 0;
	}
}

static int	handle_idle(t_data *data)
{
	if (data->flag.focus == 1)
	{
		clamp_frames(&data->tv, &data->tz, &data->frames, &data->flag.render);
	}
	if (data->flag.focus == 1 && data->flag.render == 1)
	{
		mlx_mouse_move(data->mlx, data->window,
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		update_data(data);
		render_pov(&data->img, &data->player, &data->map);
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
