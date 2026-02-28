/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:19:01 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/28 19:12:01 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_direction(char c);
static void	parse_pos(t_map *map, int row, int col);

void	parse_player_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->row_number)
	{
		col = 0;
		while (col < map->col_number)
		{
			if (is_direction(map->layout[row][col]))
			{
				if (map->starting_dir == UNINITIALIZED)
					parse_pos(map, row, col);
				else
				{
					destroy_map(map);
					error_exit("Error\ncub3d: Multiple starting positions");
				}
			}
			col++;
		}
		row++;
	}
}

static int	is_direction(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	parse_pos(t_map *map, int row, int col)
{
	map->starting_pos.x = col;
	map->starting_pos.y = row;
	if (map->layout[row][col] == 'N')
		map->starting_dir = NORTH;
	else if (map->layout[row][col] == 'S')
		map->starting_dir = SOUTH;
	else if (map->layout[row][col] == 'E')
		map->starting_dir = EAST;
	else if (map->layout[row][col] == 'W')
		map->starting_dir = WEST;
}
