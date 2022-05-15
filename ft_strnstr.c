/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:45:07 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/11 19:23:21 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check_str(const char *b, const char *l, int i, size_t *ps)
{
	size_t	j;
	size_t	len;

	j = 0;
	len = ft_strlen(l);
	while (l[j] != '\0' && *ps > 0)
	{
		if (b[i] != l[j])
			return (0);
		i++;
		j++;
		(*ps)--;
		len--;
	}
	if (len > 0 && *ps == 0)
		return (0);
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	*ps;
	size_t	r;

	i = 0;
	ps = &len;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > 0)
	{
		if (big[i] == little[0])
		{
			r = ft_check_str(big, little, i, ps);
			if (r != 0)
				return ((char *)big + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
