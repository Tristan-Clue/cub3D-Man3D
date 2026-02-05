/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:13:34 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 19:03:23 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Apply function f with every character in s passed as a parameter*/
/* Save the return result in a new string then return it */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*host;
	unsigned int	i;

	if (!s)
		return (NULL);
	host = ft_calloc(ft_strlen(s) + 1, 1);
	if (host == NULL)
		return (NULL);
	if (f)
	{
		i = 0;
		while (s[i])
		{
			host[i] = f(i, s[i]);
			i++;
		}
	}
	return (host);
}
