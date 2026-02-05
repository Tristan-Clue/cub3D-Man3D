/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:19:41 by kchiang           #+#    #+#             */
/*   Updated: 2025/12/18 14:41:19 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

/* ft_strlen but with separator set check as well */
static int	ft_wordlen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (!ft_strchr(set, *s) && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/* move across s and allocata memory for every word */
static int	ft_fillhost(char **host, const char *s, const char *set, int word)
{
	int	i;
	int	depth;
	int	wordlen;

	i = 0;
	depth = 0;
	while (depth < word)
	{
		if (!ft_strchr(set, s[i])
			&& (i == 0 || (i > 0 && ft_strchr(set, s[i - 1]))))
		{
			wordlen = ft_wordlen(&s[i], set);
			host[depth] = malloc(wordlen + 1);
			if (host == NULL)
			{
				while (depth >= 0)
					free(host[depth--]);
				return (free(host), false);
			}
			ft_strlcpy(host[depth], &s[i], wordlen + 1);
			depth++;
		}
		i++;
	}
	return (true);
}

/* split s into individual word in an array and return it */
char	**ft_split(const char *s, const char *set)
{
	int		i;
	int		word;
	char	**host;

	if (!s)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (!ft_strchr(set, s[i]) && ft_strchr(set, s[i + 1]))
			word++;
		i++;
	}
	host = malloc((word + 1) * sizeof(char *));
	if (!host)
		return (NULL);
	host[word] = NULL;
	if (ft_fillhost(host, s, set, word))
		return (host);
	return (NULL);
}
