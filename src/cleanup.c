/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:02:36 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/26 17:49:59 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
		free(map->textures[i++]);
	*map = (t_map){0};
	return ;

void	destroy_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return ;
}
