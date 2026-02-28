/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/28 23:54:09 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

int			parse_tex(t_map *map, char *line, int fd);
void		parse_player_pos(t_map *map);

static void	get_elements(int fd, t_map *map);
static void	check_layout(t_map *map);
static void	init_2d_grid(char grid[][MAX_MAP_SIZE], int value);

void	parse_map(t_map *map, const char *s)
{
	const char	*ext = ft_strrchr(s, '.');
	int			fd;

	if (!ext || ft_strcmp(ext, ".cub"))
		error_exit("Error\ncub3d: invalid config filename");
	fd = open(s, O_RDONLY);
	if (fd == -1)
		perror_exit("Error\ncub3d");
	get_elements(fd, map);
	close(fd);
	parse_player_pos(map);
	check_layout(map);
	return ;
}

static void	get_elements(int fd, t_map *map)
{
	char	*line;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n") && parse_tex(map, line, fd))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!line || !map->bgcolor_set[CEILING] || !map->bgcolor_set[FLOOR]
		|| !map->tx_path[NORTH] || !map->tx_path[SOUTH]
		|| !map->tx_path[EAST] || !map->tx_path[WEST])
	{
		free(line);
		close(fd);
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid configs");
	}
	init_2d_grid(map->layout, ' ');
	parse_layout(map, line, fd);
	return ;
}

static void	check_layout(t_map *map)
{
	char	mask[MAX_MAP_SIZE][MAX_MAP_SIZE];

	init_2d_grid(mask, false);
}

static void	init_2d_grid(char grid[][MAX_MAP_SIZE], int value)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX_MAP_SIZE)
	{
		j = 0;
		while (j < MAX_MAP_SIZE)
			grid[i][j++] = value;
		i++;
	}
	return ;
}
