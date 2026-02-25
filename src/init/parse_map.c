/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/25 17:46:52 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/* WARN: Double check get_pathr get_next_line logic
 * TODO: Element tokenizing
* */

int			parse_tex(t_map *map, char *line, int fd);

static void	get_elements(int fd, t_map *map);

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
		|| !map->textures[NORTH] || !map->textures[SOUTH]
		|| !map->textures[EAST] || !map->textures[WEST])
	{
		free(line);
		close(fd);
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid configs");
	}
	parse_layout(map, line, fd);
	return ;
}
