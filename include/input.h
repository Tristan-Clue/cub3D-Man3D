/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:46:34 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/27 21:10:48 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "cub3d.h"

// WIP: Bitmaskingggg aaaaaaaaaaaaaaaaa
// No escape from the bitmasking
typedef struct s_input
{
	int	movement;
	int	rotation;
	int	mouse_x;
	int	mouse_y;
}			t_input;

#endif
