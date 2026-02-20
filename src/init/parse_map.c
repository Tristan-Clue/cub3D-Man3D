/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 08:06:39 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/20 08:14:58 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	parse_map(t_map *map, const char *s)
{
	const char	*ext = ft_strrchr(s, '.');

	if (!ext)
		error_exit("cub3d: invalid config filename");
}
