/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:52:17 by rukobaya          #+#    #+#             */
/*   Updated: 2022/12/16 10:56:26 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, ft_strlen(s) + 1);
	return (p);
}
