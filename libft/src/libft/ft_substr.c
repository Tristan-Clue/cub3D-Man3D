/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:45:41 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:06:54 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* return a substring starting the start index of s */
/* len is the MAX string length of the substring    */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*host;
	size_t	srclen;

	if (s == NULL)
		return (NULL);
	srclen = ft_strlen(s);
	if (len == 0 || srclen < start)
		return (ft_calloc(1, 1));
	if (len > srclen - start)
		len = srclen - start;
	host = (char *)malloc(len + 1);
	if (host == NULL)
		return (NULL);
	ft_strlcpy(host, &s[start], len + 1);
	return (host);
}
