/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/24 13:42:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/* WARN: Double check get_pathr get_next_line logic
 * TODO: Element tokenizing
* */

void		parse_element(t_map *map, char *line);

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
		if (ft_strcmp(line, "\n"))
			parse_element(map, line);
		free(line);
		line = get_next_line(fd);
	}
	if ()
}
