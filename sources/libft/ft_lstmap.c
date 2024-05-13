/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:01:30 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/21 20:09:00 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*curr;
	void	*cont;

	start = NULL;
	if (!lst || !f || !del)
		return (start);
	while (lst)
	{
		cont = f(lst->content);
		curr = ft_lstnew(cont);
		if (!curr)
		{
			del(cont);
			ft_lstclear(&start, del);
			return (start);
		}
		ft_lstadd_back(&start, curr);
		lst = lst->next;
	}
	return (start);
}
