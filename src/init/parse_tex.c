/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:25:04 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/25 15:38:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdbool.h>

static void	get_path(t_map *map, char *str, t_direction direction, int fd);
static void	get_color(t_map *map, char *str, char type, int fd);

int	parse_tex(t_map *map, char *line, int fd)
{
	if (!ft_strncmp(line, "NO ", 3))
		get_path(map, line + 3, NORTH, fd);
	else if (!ft_strncmp(line, "SO ", 3))
		get_path(map, line + 3, SOUTH, fd);
	else if (!ft_strncmp(line, "WE ", 3))
		get_path(map, line + 3, WEST, fd);
	else if (!ft_strncmp(line, "EA ", 3))
		get_path(map, line + 3, EAST, fd);
	else if (!ft_strncmp(line, "F ", 2))
		get_color(map, line + 2, 'F', fd);
	else if (!ft_strncmp(line, "C ", 2))
		get_color(map, line + 2, 'C', fd);
	else if (!map->bgcolor_set[CEILING] || !map->bgcolor_set[FLOOR]
		|| !map->textures[NORTH] || !map->textures[SOUTH]
		|| !map->textures[EAST] || !map->textures[WEST])
	{
		close(fd);
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid or incomplete configs");
	}
	else
		return (1);
	return (0);
}

static void	get_path(t_map *map, char *str, t_direction direction, int fd)
{
	int	texfd;

	texfd = open(str, O_RDONLY);
	if (texfd == -1)
	{
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	close(texfd);
	map->textures[direction] = ft_strdup(str);
	if (!map->textures[direction])
	{
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	return ;
}

static void	get_color(t_map *map, char *str, char type, int fd)
{
	if (!*str)
	{
		close(fd);
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid bgcolor values");
	}
}
