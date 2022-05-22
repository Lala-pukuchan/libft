/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:05:03 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/13 08:30:25 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)ft_calloc(1, len + 1);
	if (!p || !s)
		return (NULL);
	if (start >= len)
		return ((char *)p);
	i = 0;
	while (s[start] != '\0' && len > 0)
	{
		p[i] = s[start];
		i++;
		start++;
		len--;
	}
	p[i] = '\0';
	return ((char *)p);
}
