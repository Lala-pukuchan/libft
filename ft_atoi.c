/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 07:57:03 by rukobaya          #+#    #+#             */
/*   Updated: 2022/05/29 16:24:44 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_create_int(const char *str)
{
	int	i;

	i = 0;
	while (*str != '\0' && '0' <= *str && *str <= '9')
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ng;

	i = 0;
	ng = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ng++;
		str++;
	}
	i = ft_create_int(str);
	if (ng == 1)
		i *= (-1);
	return (i);
}
