/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:24:08 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/06 20:38:31 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

/*
* Prototypes
ON_KEYDOWN 	2 	int (*f)(int keycode, void *param)
ON_KEYUP* 	3 	int (*f)(int keycode, void *param)
ON_MOUSEDOWN* 	4 	int (*f)(int button, int x, int y, void *param)
ON_MOUSEUP 	5 	int (*f)(int button, int x, int y, void *param)
ON_MOUSEMOVE 	6 	int (*f)(int x, int y, void *param)
ON_EXPOSE* 	12 	int (*f)(void *param)
ON_DESTROY 	17 	int (*f)(void *param)
*/

static int	handle_key_press(int keysym, t_data *data);
static int	handle_key_release(int keysym, t_data *data);
static int	handle_motion(int x, int y, t_data *data);
static int	reset_flag(t_data *data);

void	detect_input(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask,
		&handle_key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask,
		&handle_key_release, data);
//	mlx_hook(data->window, ButtonPress, ButtonPressMask,
//		&handle_mouse_press, data);
//	mlx_hook(data->window, ButtonRelease, ButtonReleaseMask,
//		&handle_mouse_release, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask,
		&handle_motion, data);
// BUG:	mlx_hook(data->window, Expose, ExposureMask, &handle_idle, data);
	// Check if needed;
	mlx_hook(data->window, FocusIn, FocusChangeMask, &reset_flag, data);
	mlx_hook(data->window, FocusOut, FocusChangeMask, &reset_flag, data);
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
/*
int	handle_mouse_press(int button, int x, int y, t_data *data)
{

}

int	handle_mouse_release(int button, int x, int y, t_data *data)
{

}
*/
// NOTE:
// Takes diff of new and old mouse coor, divide by mouse sense
// (Higher mouse sense, slower rotate)
static int	handle_motion(int x, int y, t_data *data)
{
	(void)y;
//	printf("%d\n", x);
	data->input.rot_angle = (x - WINDOW_WIDTH / 2) / MOUSE_SENSE;
	return (SUCCESS);
}

static int	reset_flag(t_data *data)
{
	data->input.movement = 0;
	data->input.rotation = 0;
	return (SUCCESS);
}
