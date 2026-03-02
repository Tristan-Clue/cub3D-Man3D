/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:01:11 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/02 17:51:52 by mjoon-yu         ###   ########.fr       */
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

void	event_loop(t_data *data)
{
	detect_input(data);
	update_data(data);
	render_pov(&data->img, &data->player, &data->map);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
	mlx_loop(data->mlx);
}
