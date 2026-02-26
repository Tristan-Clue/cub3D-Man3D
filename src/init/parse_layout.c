/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_layout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:10:25 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/26 17:48:56 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdbool.h>

static int	contain_illegal_ch(char *s);
static void	copy_line(t_map *map, char *line, int row);

void	parse_layout(t_map *map, char *line, int fd)
{
	int	row;

	row = 0;
	while (line)
	{
		if (contain_illegal_ch(line) || row >= MAX_MAP_SIZE)
		{
			free(line);
			close(fd);
			destroy_map(map);
			error_exit("Error\ncub3d: Invalid map");
		}
		copy_line(map, line, row);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	return ;
}

static int	contain_illegal_ch(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i >= MAX_MAP_SIZE)
			return (true);
		if (!(s[i] == ' ' || s[i] == '0' || s[i] == '1' || s[i] == 'N'
			|| s[i] == 'S' || s[i] == 'E' || s[i] == 'W'))
			return (true);
		i++;
	}
	return (false);
}

static void	copy_line(t_map *map, char *line, int row)
{
	int	i;

	i = 0;
	while (line[i] && i < MAX_MAP_SIZE)
	{
		map->layout[row][i] = line[i];
		i++;
	}
	return ;
}
