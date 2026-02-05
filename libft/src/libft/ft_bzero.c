/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:18:20 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:50:15 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// replace the first n bytes pointed by s with zeroes
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	if (!s)
		return ;
	temp = (unsigned char *)s;
	while (n-- > 0)
		*temp++ = 0;
	return ;
}
