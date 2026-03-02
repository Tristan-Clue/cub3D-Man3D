/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 13:25:04 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/02 19:38:01 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void		get_color(t_map *map, char *str, char type, int fd);
void		skip_spaces(char **tmp);
static void	get_path(t_map *map, char *str, t_direction direction, int fd);

int	parse_tex(t_map *map, char *line, int fd)
{
	char	*tmp;

	tmp = line;
	while (*tmp == ' ')
		tmp++;
	if (!ft_strncmp(tmp, "NO ", 3) && !map->tx_path[NORTH])
		get_path(map, line, NORTH, fd);
	else if (!ft_strncmp(tmp, "SO ", 3) && !map->tx_path[SOUTH])
		get_path(map, line, SOUTH, fd);
	else if (!ft_strncmp(tmp, "WE ", 3) && !map->tx_path[WEST])
		get_path(map, line, WEST, fd);
	else if (!ft_strncmp(tmp, "EA ", 3) && !map->tx_path[EAST])
		get_path(map, line, EAST, fd);
	else if (!ft_strncmp(tmp, "F ", 2) && !map->bgcolor_set[FLOOR])
		get_color(map, line, 'F', fd);
	else if (!ft_strncmp(tmp, "C ", 2) && !map->bgcolor_set[CEILING])
		get_color(map, line, 'C', fd);
	else
		return (1);
	return (0);
}

static void	get_path(t_map *map, char *str, t_direction direction, int fd)
{
	int		texfd;
	char	*tmp;

	tmp = str;
	skip_spaces(&tmp);
	printf("%s\n", tmp);	// BUG: Here, there's a trailing newline
	texfd = open(tmp, O_RDONLY);
	if (texfd == -1)
	{
		free(str);
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	close(texfd);
	map->tx_path[direction] = ft_strdup(tmp + 3);
	if (!map->tx_path[direction])
	{
		free(str);
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
}
