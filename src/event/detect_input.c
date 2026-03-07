/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:24:08 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/07 20:20:03 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

static int	handle_key_press(int keysym, t_data *data);
static int	handle_key_release(int keysym, t_data *data);
static int	handle_motion(int x, int y, t_data *data);
static int	focus_in(t_data *data);
static int	focus_out(t_data *data);

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

static int	handle_key_press(int keysym, t_data *data)
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

static int	handle_key_release(int keysym, t_data *data)
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

static int	handle_motion(int x, int y, t_data *data)
{
	(void)y;
//	printf("%d\n", x);
	if (data->flag.focus == 1)
		data->input.rot_angle = (x - WINDOW_WIDTH / 2) / MOUSE_SENSE;
	return (SUCCESS);
}

static int	focus_out(t_data *data)
{
	data->input.movement = 0;
	data->input.rotation = 0;
	data->flag.focus = 0;
	data->flag.render = 0;
//	printf("Focus out\n");
	return (SUCCESS);
}

static int focus_in(t_data *data)
{
	data->flag.focus = 1;
	data->flag.render = 1;
//	printf("Focus in\n");
	return (SUCCESS);
}
