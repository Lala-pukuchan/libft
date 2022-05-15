/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:58:15 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/16 17:57:58 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_getpower(int p)
{
	int	tenpower;

	tenpower = 1;
	while (p-- > 0)
		tenpower *= 10;
	return (tenpower);
}

int	ft_getdigit(int n)
{
	int	count;

	count = 0;
	while (n > 1)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

void	ft_convertint(char *str, int index, int n, int digit)
{
	while (1 < digit)
	{
		str[index++] = '0' + (n / ft_getpower(digit - 1));
		n %= ft_getpower(digit - 1);
		digit--;
	}
	str[index++] = '0' + (n % 10);
	str[index] = '\0';
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*str;
	int		index;

	index = 0;
	if (n < 0)
	{
		n *= (-1);
		digit = ft_getdigit(n);
		str = malloc(digit + 2);
		str[index++] = '-';
	}
	else
	{
		digit = ft_getdigit(n);
		str = malloc(digit + 1);
	}
	if (!str)
		return (NULL);
	ft_convertint(str, index, n, digit);
	return (str);
}
