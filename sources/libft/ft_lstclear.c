/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:47:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 16:10:09 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	node = *lst;
	*lst = NULL;
	while (node)
	{
		del(node->content);
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
