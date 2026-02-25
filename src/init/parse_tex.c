/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:25:04 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/25 17:57:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

void		get_color(t_map *map, char *str, char type, int fd);

static void	get_path(t_map *map, char *str, t_direction direction, int fd);

int	parse_tex(t_map *map, char *line, int fd)
{
	if (!ft_strncmp(line, "NO ", 3) && !map->textures[NORTH])
		get_path(map, line, NORTH, fd);
	else if (!ft_strncmp(line, "SO ", 3) && !map->textures[SOUTH])
		get_path(map, line, SOUTH, fd);
	else if (!ft_strncmp(line, "WE ", 3) && !map->textures[WEST])
		get_path(map, line, WEST, fd);
	else if (!ft_strncmp(line, "EA ", 3) && !map->textures[EAST])
		get_path(map, line, EAST, fd);
	else if (!ft_strncmp(line, "F ", 2) && !map->bgcolor_set[FLOOR])
		get_color(map, line, 'F', fd);
	else if (!ft_strncmp(line, "C ", 2) && !map->bgcolor_set[CEILING])
		get_color(map, line, 'C', fd);
	else
		return (1);
	return (0);
}

static void	get_path(t_map *map, char *str, t_direction direction, int fd)
{
	int	texfd;

	texfd = open(str + 3, O_RDONLY);
	if (texfd == -1)
	{
		free(str);
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	close(texfd);
	map->textures[direction] = ft_strdup(str + 3);
	if (!map->textures[direction])
	{
		free(str);
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
}
