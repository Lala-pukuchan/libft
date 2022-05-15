/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 08:44:36 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/16 10:02:52 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_getcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

void	ft_createstr(char	**array, char const *s, char c)
{
	size_t	index;
	size_t	ai;
	size_t	si;

	index = 0;
	ai = 0;
	si = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c || index == (ft_strlen(s) - 1))
		{
			array[ai] = malloc(index - si + 1);
			if (index != (ft_strlen(s) - 1))
				ft_strlcpy(array[ai], &s[si], index - si + 1);
			else
				ft_strlcpy(array[ai], &s[si], index - si + 2);
			ai++;
			si = index + 1;
		}
		index++;
	}
	array[ai] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = malloc(sizeof(char *) * (ft_getcount(s, c) + 1));
	if (!array)
		return (NULL);
	ft_createstr(array, s, c);
	return (array);
}
