/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:28:26 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 18:31:36 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *nptr, const char *base)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	if (!nptr)
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr && ft_strchr(base, *nptr))
	{
		nbr *= ft_strlen(base);
		nbr += ft_strchr(base, *nptr) - base;
		nptr++;
	}
	return (nbr * sign);
}
