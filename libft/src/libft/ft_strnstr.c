/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:07:07 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:05:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* locate a little substring in big */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (!big)
		return (NULL);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (len > 0 && *big)
	{
		if (len < little_len)
			return (NULL);
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}
