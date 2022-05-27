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

int	ft_count_delimiter(char const *s, char c)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

char	**ft_free_array(char	**array, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(array[idx]);
		array[idx] = NULL;
	}
	free(array);
	array = NULL;
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	int		len;
	int		idx;
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_count_delimiter(s, c) + 1));
	if (!array)
		return (NULL);
	idx = 0;
	while (*s != '\0')
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		len = 0;
		while ((*s != c) && (*s != '\0'))
		{
			s++;
			len++;
		}
		if (len != 0)
		{
			array[idx] = ft_substr(s - len, 0, len);
			if (!array[idx])
				return(ft_free_array(array, idx));
			idx++;
		}
	}
	array[idx] = NULL;
	return (array);
}
