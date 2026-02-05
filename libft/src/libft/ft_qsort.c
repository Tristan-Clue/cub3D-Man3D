/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:52:24 by kchiang           #+#    #+#             */
/*   Updated: 2025/11/05 23:54:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	swap_element(void *e1, void *e2, size_t size);

void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*compar)(const void *, const void *))
{
	size_t	pivot;
	size_t	i;

	if (nmemb > 1)
	{
		pivot = 0;
		i = 0;
		while (i < nmemb - 1)
		{
			if (compar((char *)base + i * size,
					(char *)base + (nmemb - 1) * size) <= 0)
				swap_element((char *)base + size * pivot++,
					(char *)base + i * size, size);
			i++;
		}
		swap_element((char *)base + pivot * size,
			(char *)base + (nmemb - 1) * size, size);
		ft_qsort(base, pivot, size, compar);
		if (pivot + 1 < nmemb - 1)
			ft_qsort((char *)base + (pivot + 1) * size,
				nmemb - pivot - 1, size, compar);
	}
	return ;
}

static void	swap_element(void *e1, void *e2, size_t size)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	tmp;

	a = (unsigned char *)e1;
	b = (unsigned char *)e2;
	while (size--)
	{
		tmp = *a;
		*a++ = *b;
		*b++ = tmp;
	}
	return ;
}
