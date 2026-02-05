/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:14:30 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/29 12:17:35 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlst.h"

/* Added new to the back of lst */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
		*lst = new;
	else
		last_node->next = new;
	return ;
}
