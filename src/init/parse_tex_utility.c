/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:55:29 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/25 18:31:29 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdbool.h>

void		skip_spaces(char **tmp);
static int	value_is_invalid(char *val);
static void	set_bg_color(t_map *map, char **values, char type);
static int	clamp_values(int value);

void	get_color(t_map *map, char *str, char type, int fd)
{
	char	**values;
	char	*tmp;
	int		i;

	tmp = str;
	skip_spaces(&tmp);
	if (value_is_invalid(tmp))
	{
		free(str);
		close(fd);
		destroy_map(map);
		error_exit("Error\ncub3d: Invalid bgcolor config");
	}
	values = ft_split(tmp, ",");
	if (!values)
	{
		free(str);
		close(fd);
		destroy_map(map);
		perror_exit("Error\ncub3d");
	}
	set_bg_color(map, values, type);
	destroy_array(values);
	return ;
}

void	skip_spaces(char **tmp)
{
	while (**tmp == ' ')
		(*tmp)++;
	*tmp += 2;
	while (**tmp == ' ')
		(*tmp)++;
	return ;
}

static int	value_is_invalid(char *val)
{
	int	i;
	int	comma;

	i = -1;
	comma = 0;
	while (val[++i])
	{
		if (val[i] == ',')
		{
			comma++;
			if (comma > 2)
				return (true);
		}
		else if (!ft_isdigit(val[i]))
			return (true);
	}
	return (!ft_isdigit(val[--i]) || comma != 2);
}

static void	set_bg_color(t_map *map, char **values, char type)
{
	const int	r = clamp_value(ft_atoi(values[0]));
	const int	g = clamp_value(ft_atoi(values[1]));
	const int	b = clamp_value(ft_atoi(values[2]));

	if (type == 'F')
	{
		map->floor_color = encode_rgb(r, g, b);
		map->bgcolor_set[FLOOR] = true;
	}
	if (type == 'C')
	{
		map->ceiling_color = encode_rgb(r, g, b);
		map->bgcolor_set[CEILING] = true;
	}
	return ;
}

static int	clamp_values(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return (value);
}
