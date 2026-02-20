/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/20 11:05:48 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/* WARN: Double check tokenizer get_next_line logic
 * TODO: Element tokenizing
* */

static int	open_file(const char *s, const char *format);

void	parse_map(t_map *map, const char *s)
{
	int		fd;
	t_list	*elements;
	
	fd = open_file(s, ".cub");
	elements = make_element_list(fd, map);
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

static t_list	*make_element_list(int fd, t_map *map)
{
	t_list	*list;
	char	*line;
	int		count;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (tokenize_element(&list, line))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	count = ft_lstsize(list);
	if (count < 6)
}

int	tokenize_element(t_list **list, char *line)
{
	if (!ft_strcmp(line, "\n"))
		return (0);
	else if (!ft_strncmp(line, "NO ", 3))
		tokenize(list, line, 'N');
	else if (!ft_strncmp(line, "SO ", 3))
		tokenize(list, line, 'S');
	else if (!ft_strncmp(line, "WE ", 3))
		tokenize(list, line, 'W');
	else if (!ft_strncmp(line, "EA ", 3))
		tokenize(list, line, 'E');
	else if (!ft_strncmp(line, "F ", 2))
		tokenize(list, line, 'F');
	else if (!ft_strncmp(line, "C ", 2))
		tokenize(list, line, 'C');
	else
		return (1);
	return (0);
}
