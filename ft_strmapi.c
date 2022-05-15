/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:08:03 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/16 18:51:00 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const	*s, char	(*f)(unsigned int, char))
{
	char	*str;
	size_t	index;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
