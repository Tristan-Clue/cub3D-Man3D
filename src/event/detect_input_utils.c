/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_input_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 12:29:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/10 12:30:57 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->input.movement |= KEY_W;
	if (keysym == XK_s)
		data->input.movement |= KEY_S;
	if (keysym == XK_a)
		data->input.movement |= KEY_A;
	if (keysym == XK_d)
		data->input.movement |= KEY_D;
	if (keysym == XK_Left)
		data->input.rotation |= KEY_LEFT;
	if (keysym == XK_Right)
		data->input.rotation |= KEY_RIGHT;
	if (keysym == XK_Escape)
		destroy(data);
	return (SUCCESS);
}

int	handle_key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->input.movement &= ~KEY_W;
	if (keysym == XK_s)
		data->input.movement &= ~KEY_S;
	if (keysym == XK_a)
		data->input.movement &= ~KEY_A;
	if (keysym == XK_d)
		data->input.movement &= ~KEY_D;
	if (keysym == XK_Left)
		data->input.rotation &= ~KEY_LEFT;
	if (keysym == XK_Right)
		data->input.rotation &= ~KEY_RIGHT;
	return (SUCCESS);
}

// NOTE:
// Takes diff of new and old mouse coor, divide by mouse sense
// (Higher mouse sense, slower rotate)

int	handle_motion(int x, int y, t_data *data)
{
	(void)y;
	if (data->flag.focus == 1)
		data->input.rot_angle = (x - WINDOW_WIDTH / 2) / MOUSE_SENSE;
	return (SUCCESS);
}

int	focus_out(t_data *data)
{
	data->input.movement = 0;
	data->input.rotation = 0;
	data->flag.focus = 0;
	data->flag.render = 0;
	return (SUCCESS);
}

int	focus_in(t_data *data)
{
	data->flag.focus = 1;
	data->flag.render = 1;
	return (SUCCESS);
}
