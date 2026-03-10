/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:24:08 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/10 12:30:57 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

int	handle_key_press(int keysym, t_data *data);
int	handle_key_release(int keysym, t_data *data);
int	handle_motion(int x, int y, t_data *data);
int	focus_in(t_data *data);
int	focus_out(t_data *data);

void	detect_input(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask,
		&handle_key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask,
		&handle_key_release, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask,
		&handle_motion, data);
	mlx_hook(data->window, FocusIn, FocusChangeMask, &focus_in, data);
	mlx_hook(data->window, FocusOut, FocusChangeMask, &focus_out, data);
	if (data->window)
		mlx_hook(data->window, 17, 0L, &destroy, data);
}
