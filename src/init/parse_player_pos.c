/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:19:01 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/28 17:30:08 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdbool.h>

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
