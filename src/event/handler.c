/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 14:24:08 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/28 15:43:32 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

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

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == XK_W)
		data->input.movement |= KEY_W;
	if (keysym == XK_S)
		data->input.movement |= KEY_S;
	if (keysym == XK_A)
		data->input.movement |= KEY_A;
	if (keysym == XK_D)
		data->input.movement |= KEY_D;
	if (keysym == XK_LEFT)
		data->input.rotation |= KEY_LEFT;
	if (keysym == XK_RIGHT)
		data->input.rotation |= KEY_RIGHT;
}

int	handle_key_release(int keysym, t_data *data)
{
	if (keysym == XK_W)
		data->input.movement &= ~KEY_W;
	if (keysym == XK_S)
		data->input.movement &= ~KEY_S;
	if (keysym == XK_A)
		data->input.movement &= ~KEY_A;
	if (keysym == XK_D)
		data->input.movement &= ~KEY_D;
	if (keysym == XK_LEFT)
		data->input.rotation &= ~KEY_LEFT;
	if (keysym == XK_RIGHT)
		data->input.rotation &= ~KEY_RIGHT;
}

int	handle_mouse_press(int button, int x, int y, t_data *data)
{

}

int	handle_mouse_release(int button, int x, int y, t_data *data)
{

}

int	handle_motion(int x, int y, t_data *data)
{
	data->input.rot_angle = x - data->input.mouse_x / MOUSE_SENSE;
	data->input.mouse_x = x;
}

int	reset_flag(t_data *data)
{

}
