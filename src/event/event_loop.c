/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:01:11 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/26 14:00:48 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>

static int	handle_mouse(int button, int x, int y, t_data *data);
static int	handle_keys(int	keysym, t_data *data);
static int	handle_idle(t_data *data);

void	event_loop(t_data *data)
{
	mlx_mouse_hook(data->window, &handle_mouse, data);
	mlx_key_hook(data->window, &handle_keys, data);
	mlx_loop_hook(data->mlx, &handle_idle, data);
	if (data->window)
		mlx_hook(data->window, 17, 0L, &destroy, data);
	mlx_loop(data->mlx);
}

static int	handle_idle(t_data *data)
{
	render_pov(&data->img, &data->player, &data->map);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
	return (SUCCESS);
}

static int	handle_keys(int	keysym, t_data *data)
{
	if (keysym == XK_Escape)
		destroy(data);
	if (keysym == XK_Left || keysym == XK_Right)
	{
		rotate_camera(keysym, data);
	}
	return (SUCCESS);
}

static int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void)data;
	(void)button;
	(void)x;
	(void)y;
	return (SUCCESS);
}
