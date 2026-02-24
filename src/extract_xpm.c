/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:25:28 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/24 12:22:59 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

/*
 * NOTE:
** Convert an xpm file to a new image instance.
**
** @param	void *mlx_ptr	the mlx instance;
** @param	char *filename	the file to load;
** @param	int  *width		a pointer to where the width ought to be written;
** @param	int  *height	a pointer to where the height ought to be written;
** @return	void*			the image instance, and NULL in case of error.
*/
// NOTE: void	*mlx_xpm_file_to_image(void *mlx_ptr,
// 				char *filename, int *width, int *height);
// 		Function will put the texture into the image pointer.
// 		Image will have to be created using mlx_new_image

void	assign_textures(t_map *map)	// Include struct with file names for NESW
{
	// WIP: Function will call function, check files beforehand during parsing?
	// Initialize image pointers for the textures
	// Image will be used for sampling to the screen during extraction for render
}
