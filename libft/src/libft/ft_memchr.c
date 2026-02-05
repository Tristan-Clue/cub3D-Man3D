/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:22:11 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:54:20 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// look for c in s for the first n bytes
// return NULL if nothing is found
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (!s)
		return (NULL);
	tmp = (unsigned char *)s;
	while (n > 0)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
