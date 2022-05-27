/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 07:57:03 by rukobaya          #+#    #+#             */
/*   Updated: 2022/05/07 16:46:01 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_create_int(char *str)
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

int	ft_atoi(char *str)
{
	int	i;
	int	ng;

	i = 0;
	ng = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ng++;
		str++;
	}
	i = ft_create_int(str);
	if (ng % 2 != 0)
		i *= (-1);
	if (i < -2147483648)
		return (0);
	if (2147483647 < i)
		return (-1);
	return (i);
}
