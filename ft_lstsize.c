/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:16:45 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/22 08:57:07 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp_ptr;

	size = 0;
	temp_ptr = lst;
	while (1)
	{
		if (temp_ptr->next == NULL)
			break ;
		temp_ptr = temp_ptr->next;
		size++;
	}
	return (size + 1);
}
