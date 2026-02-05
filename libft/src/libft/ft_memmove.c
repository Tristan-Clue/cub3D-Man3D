/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:14:12 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:55:41 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// If dest is in front of src, ft_memcpy as usual.
// If dest is behind src, to prevent overlapping, ft_memcpy backwards.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (!dest || !src || n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	while (n-- > 0)
		temp_dest[n] = temp_src[n];
	return (dest);
}
