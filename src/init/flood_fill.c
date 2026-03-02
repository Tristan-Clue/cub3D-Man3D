/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:46:35 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/02 17:19:52 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>

static int	scan_wall(t_map *map, char mask[][MAX_MAP_SIZE], int row, int col);

int	scan_space(t_map *map, char mask[][MAX_MAP_SIZE], int row, int col)
{
	if (mask[row][col] == true)
		return (SUCCESS);
	if (map->layout[row][col] == '1')
		return (scan_wall(map, mask, row, col));
	if (row == 0 || row == map->row_number - 1
		|| col == 0 || col == map->col_number - 1)
		return (FAILURE);
	if (map->layout[row][col] == '0'
		|| (row == map->starting_pos.x && col == map->starting_pos.y))
	{
		mask[row][col] = true;
		return (scan_space(map, mask, row - 1, col)
			|| scan_space(map, mask, row + 1, col)
			|| scan_space(map, mask, row, col - 1)
			|| scan_space(map, mask, row, col + 1));
	}
	return (FAILURE);
}

static int	scan_wall(t_map *map, char mask[][MAX_MAP_SIZE], int row, int col)
{
	if (row < 0 || row == map->row_number || col < 0 || col == map->col_number
		|| mask[row][col] == true || map->layout[row][col] == ' ')
		return (SUCCESS);
	if (map->layout[row][col] == '0')
		return (scan_space(map, mask, row, col));
	if (map->layout[row][col] == '1')
	{
		mask[row][col] = true;
		return (scan_wall(map, mask, row - 1, col)
			|| scan_wall(map, mask, row - 1, col - 1)
			|| scan_wall(map, mask, row - 1, col + 1)
			|| scan_wall(map, mask, row + 1, col)
			|| scan_wall(map, mask, row + 1, col - 1)
			|| scan_wall(map, mask, row + 1, col + 1)
			|| scan_wall(map, mask, row, col - 1)
			|| scan_wall(map, mask, row, col + 1));
	}
	return (SUCCESS);
}
