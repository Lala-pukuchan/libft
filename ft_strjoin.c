/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:30:57 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/13 08:41:47 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ft_calloc(1, ft_strlen(s1) + ft_strlen(s2));
	if (!p || !s1 || !s2)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		p[i++] = *s1++;
	while (*s2 != '\0')
		p[i++] = *s2++;
	return ((char *)p);
}
