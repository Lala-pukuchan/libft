/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 08:37:12 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/22 09:01:38 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*target;
	t_list	*temp;

	target = *lst;
	while (target->next != NULL)
	{
		temp = target->next;
		ft_lstdelone(target, del);
		target = temp;
	}
	*lst = NULL;
}
