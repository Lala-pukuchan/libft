/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:49:52 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/16 09:13:55 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] != '\0' && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, str + start, end - start + 1);
	return (str);
}
