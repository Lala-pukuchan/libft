/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:09:58 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/21 08:38:51 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (1)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}
