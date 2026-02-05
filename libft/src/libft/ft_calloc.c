/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:10:40 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:50:38 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

/* allocate memory for nmemb elements with size bytes each */
/* if nmemb or size is 0, return a unique pointer */
/* if nmemb * size > ULONG_MAX, return NULL */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*host;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((SIZE_MAX / nmemb) < size)
		return (NULL);
	host = malloc(nmemb * size);
	if (host)
		return (ft_memset(host, 0, nmemb * size));
	return (NULL);
}
