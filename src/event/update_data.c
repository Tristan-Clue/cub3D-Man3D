/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:16:57 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/03/04 18:48:44 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>

void	update_data(t_data *data)
{
	handle_movement(&data->input, &data->player, &data->map);
	rotate_camera(&data->input, &data->player);
}
