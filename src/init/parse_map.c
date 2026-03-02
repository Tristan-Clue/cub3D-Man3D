/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/02 18:07:11 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

int			parse_tex(t_map *map, char *line, int fd);
void		parse_player_pos(t_map *map);
int			scan_space(t_map *map, char mask[][MAX_MAP_SIZE], int row, int col);
void	parse_layout(t_map *map, char *line, int fd);

static void	get_elements(int fd, t_map *map);
static void	check_layout(t_map *map);
static void	init_2d_grid(char grid[][MAX_MAP_SIZE], int value);
static int	mask_has_error(t_map *map, char mask[][MAX_MAP_SIZE]);

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
	if (scan_space(map, mask, (int)map->starting_pos.y,
			(int)map->starting_pos.x) == FAILURE || mask_has_error(map, mask))
	{
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid map");
	}
	return ;
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

static int	mask_has_error(t_map *map, char mask[][MAX_MAP_SIZE])
{
	int	row;
	int	col;

	row = 0;
	while (row < map->row_number)
	{
		col = 0;
		while (col < map->col_number)
		{
			if (map->layout[row][col] != ' ' && mask[row][col] == false)
				return (true);
			col++;
		}
		row++;
	}
	return (false);
}
