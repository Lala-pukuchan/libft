/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya <rukobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:13:21 by rukobaya          #+#    #+#             */
/*   Updated: 2022/04/18 19:21:02 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (-10 < n && n < 0)
			ft_putchar_fd('-', fd);
		if (n <= -10 || 10 <= n)
			ft_putnbr_fd(n / 10, fd);
		n = n % 10;
		if (n < 0)
			n *= -1;
		ft_putchar_fd('0' + n, fd);
	}
}
