/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:29:57 by rukobaya          #+#    #+#             */
/*   Updated: 2022/05/07 14:31:41 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	rv;

	if (!dst)
		return (99);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size > dlen)
		rv = dlen + slen;
	else
		rv = size + slen;
	if (size == 0)
		return (rv);
	i = 0;
	while (src[i] != '\0' && (dlen + 1) < size)
	{
		dst[dlen] = src[i];
		dlen++;
		i++;
	}
	dst[dlen] = '\0';
	return (rv);
}
