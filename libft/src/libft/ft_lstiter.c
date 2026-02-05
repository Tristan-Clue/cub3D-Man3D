/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:34:17 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/29 12:18:07 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlst.h"

/* Apply function f on the content of each node in lst */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
	return ;
}
