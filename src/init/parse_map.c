/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/23 17:03:29 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/* WARN: Double check get_pathr get_next_line logic
 * TODO: Element tokenizing
* */

static int	open_file(const char *s, const char *format);

void	parse_map(t_map *map, const char *s)
{
	int		fd;
	
	fd = open_file(s, ".cub");
	get_elements(fd, map);
	close(fd);
	return ;
}

static int	open_file(const char *s, const char *format)
{
	const char	*ext = ft_strrchr(s, '.');
	int			fd;

	if (!ext || ft_strcmp(ext, format))
		error_exit("Error\ncub3d: invalid config filename");
	fd = open(s, O_RDONLY);
	if (fd == -1)
		perror_exit("Error\ncub3d");
	return (fd);
}

static void	get_elements(int fd, t_map *map)
{
	char	*line;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (parse_element(map, line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
}

static int	parse_element(t_map *map, char *line)
{
	if (!ft_strcmp(line, "\n"))
		return (0);
	else if (!ft_strncmp(line, "NO ", 3))
		get_path(map, line, 'N');
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
	else
		return (1);
	return (0);
}
