/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/27 16:31:50 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>

int			parse_tex(t_map *map, char *line, int fd);

static void	get_elements(int fd, t_map *map);
static void	check_layout(t_map *map);
static void	init_mask(char mask[][MAX_MAP_SIZE]);

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
	check_player_pos(map);	// TODO:
	check_layout(map);		// TODO:
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
	parse_layout(map, line, fd);
	return ;
}

static void	check_layout(t_map *map)
{
	char	mask[MAX_MAP_SIZE][MAX_MAP_SIZE];

	init_mask(mask);
}

static void	init_mask(char mask[][MAX_MAP_SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX_MAP_SIZE)
	{
		j = 0;
		while (j < MAX_MAP_SIZE)
			mask[i][j++] = false;
		i++;
	}
	return ;
}
