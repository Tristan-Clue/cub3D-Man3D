/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:25:04 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/24 13:42:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

static int	elements_not_set(t_map *map);

void	parse_element(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		get_element(map, line, 'N');
	else if (!ft_strncmp(line, "SO ", 3))
		get_path(map, line, 'S');
	else if (!ft_strncmp(line, "WE ", 3))
		get_path(map, line, 'W');
	else if (!ft_strncmp(line, "EA ", 3))
		get_path(map, line, 'E');
	else if (!ft_strncmp(line, "F ", 2))
		get_color(map, line, 'F');
	else if (!ft_strncmp(line, "C ", 2))
		get_color(map, line, 'C');
	else if (elements_not_set(map))
		error_exit("Error\ncub3d: Invalid config");
	return ;
}

static int	elements_not_set(t_map *map)
{
	return (!map->bgcolor_set[CEILING] || !map->bgcolor_set[FLOOR]
		|| !map->textures[NORTH] || !map->textures[SOUTH]
	 	|| !map->textures[EAST] || !map->textures[WEST]);
}
