/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:01:11 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/06 20:33:03 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

// NOTE: 	Expose required for redraw?
// 			Check FocusIn/Out requirements to reset flags
// 			Setting flags for hold keys
static int	handle_idle(t_data *data)
{
	mlx_mouse_move(data->mlx, data->window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	update_data(data);
	render_pov(&data->img, &data->player, &data->map);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
	return (SUCCESS);
}

void	event_loop(t_data *data)
{
	mlx_mouse_move(data->mlx, data->window, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	detect_input(data);
	mlx_loop_hook(data->mlx, &handle_idle, data);
	mlx_loop(data->mlx);
}
