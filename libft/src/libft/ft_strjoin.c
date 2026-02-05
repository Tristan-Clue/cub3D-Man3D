/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:52:10 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:01:23 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* return the combination of s1 and s2. NULL if failed */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*host;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	host = ft_calloc(len1 + len2 + 1, 1);
	if (host)
	{
		ft_strlcat(host, s1, len1 + len2 + 1);
		ft_strlcat(host, s2, len1 + len2 + 1);
		return (host);
	}
	return (NULL);
}
