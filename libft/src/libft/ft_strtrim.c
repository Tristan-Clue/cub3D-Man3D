/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:35:06 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:06:32 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Return copy of s1 with chars specidfied in 'set' removed from */
/* the beginning and the end of s1. */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	char	*host;

	if (!s1)
		return (NULL);
	if (!set || !*set || !*s1)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	while (ft_strchr(set, *s1))
	{
		s1++;
		if (--len == 0)
			return (ft_calloc(1, 1));
	}
	while (ft_strchr(set, *(s1 + len - 1)))
		len--;
	host = ft_calloc(len + 1, 1);
	if (host == NULL)
		return (NULL);
	ft_strlcpy(host, s1, len + 1);
	return (host);
}
