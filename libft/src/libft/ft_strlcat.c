/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:12:01 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:01:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// replicating strlcat
// concatenate src to dest without causing overflow
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dest)
		return (size + src_len);
	dest_len = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	if (size <= dest_len)
		return (size + src_len);
	if (!src)
		return (dest_len + src_len);
	i = 0;
	while ((dest_len + i < size - 1) && *src)
		dest[dest_len + i++] = *src++;
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
