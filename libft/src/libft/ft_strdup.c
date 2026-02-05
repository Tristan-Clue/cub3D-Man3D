/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:11:14 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:00:13 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* duplicate a string using malloc then return it */
char	*ft_strdup(const char *src)
{
	char	*host;
	size_t	len;
	size_t	i;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	host = (char *)malloc(len + 1);
	if (host == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		host[i] = src[i];
		i++;
	}
	host[i] = '\0';
	return (host);
}
