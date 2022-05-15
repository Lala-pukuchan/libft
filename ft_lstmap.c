/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 09:42:04 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/23 11:39:50 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&ptr, del);
		return (NULL);
	}
	ptr = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr, new);
	}
	return (ptr);
}
