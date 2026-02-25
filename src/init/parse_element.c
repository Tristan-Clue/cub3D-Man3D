/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:25:04 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/25 15:19:42 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdbool.h>

void	parse_element(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		get_path(map, line + 3, NORTH);
	else if (!ft_strncmp(line, "SO ", 3))
		get_path(map, line + 3, SOUTH);
	else if (!ft_strncmp(line, "WE ", 3))
		get_path(map, line + 3, WEST);
	else if (!ft_strncmp(line, "EA ", 3))
		get_path(map, line + 3, EAST);
	else if (!ft_strncmp(line, "F ", 2))
		get_color(map, line + 2, 'F');
	else if (!ft_strncmp(line, "C ", 2))
		get_color(map, line + 2, 'C');
	else if (!map->bgcolor_set[CEILING] || !map->bgcolor_set[FLOOR]
		|| !map->textures[NORTH] || !map->textures[SOUTH]
	 	|| !map->textures[EAST] || !map->textures[WEST])
		error_exit("Error\ncub3d: Invalid config settings");
	return ;
}

static void	get_path(t_map *map, char *str, t_direction direction)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	close(fd);
	map->textures[direction] = ft_strdup(str);
	if (!map->textures[direction])
	{
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	return ;
}

static void	get_color(t_map *map, char *str, char type)
{
	if (!*str)
	{
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid bgcolor values");
	}
}
