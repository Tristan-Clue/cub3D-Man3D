/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:53:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:51:39 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert integer to a string */
char	*ft_itoa(long long nbr)
{
	char	tmp[20];
	int		depth;
	int		is_neg;

	is_neg = 0;
	depth = 19;
	tmp[depth] = '\0';
	tmp[18] = '0';
	if (nbr == 0)
		return (ft_strdup(&tmp[18]));
	if (nbr < 0)
	{
		is_neg = 1;
		nbr = -nbr;
	}
	while (nbr)
	{
		tmp[--depth] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_neg)
		tmp[--depth] = '-';
	return (ft_strdup(&tmp[depth]));
}
