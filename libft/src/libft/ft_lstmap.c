/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:40:07 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/29 12:17:57 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftlst.h"

/* Apply function f on the content of each node in lst */
/* Copy the whole lst to a new list */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	first_node = ft_lstnew(f(lst->content));
	if (!first_node)
		return (NULL);
	lst = lst->next;
	current = first_node;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		if (current->next == NULL)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (first_node);
}
