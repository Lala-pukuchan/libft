/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:47:14 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/16 08:13:28 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	n;

	if (c > 127)
		c %= 128;
	if (c < 0)
		c = c % 128 + 128;
	
	i = 0;
	n = ft_strlen(s) + 1;
	while (n > 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
		n--;
	}
	return (NULL);
}
