/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:32:25 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:55:10 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// copy n bytes from src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	if (!src || !dest)
		return (dest);
	temp_src = (unsigned char *)src;
	temp_dest = (unsigned char *)dest;
	while (n-- > 0)
		*temp_dest++ = *temp_src++;
	return (dest);
}
