/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:25:04 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/24 14:02:12 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdbool.h>

void	parse_element(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		parse_value(map, line + 3, 'N');
	else if (!ft_strncmp(line, "SO ", 3))
		parse_value(map, line + 3, 'S');
	else if (!ft_strncmp(line, "WE ", 3))
		parse_value(map, line + 3, 'W');
	else if (!ft_strncmp(line, "EA ", 3))
		parse_value(map, line + 3, 'E');
	else if (!ft_strncmp(line, "F ", 2))
		parse_value(map, line + 2, 'F');
	else if (!ft_strncmp(line, "C ", 2))
		parse_value(map, line + 2, 'C');
	else if (!map->bgcolor_set[CEILING] || !map->bgcolor_set[FLOOR]
		|| !map->textures[NORTH] || !map->textures[SOUTH]
	 	|| !map->textures[EAST] || !map->textures[WEST])
		error_exit("Error\ncub3d: Invalid config settings");
	return ;
}

void	parse_value(t_map *map, char *str, char type)
{
	if (!*str)
	{
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid config values");
}
