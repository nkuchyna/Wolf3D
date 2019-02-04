/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:31:42 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/28 17:12:48 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_check_putnbr_fd(int n, int *d)
{
	if ((n > -2147483648 && n < -999999999) ||
		(n <= 2147483647 && n > 999999999))
		(*d) = 1000000000;
	else
	{
		while (n / (*d) != 0)
			(*d) *= 10;
		if (n != 0)
			(*d) = (*d) / 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int		d;
	char	c;

	d = 1;
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	ft_check_putnbr_fd(n, &d);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (d > 0)
	{
		c = n / d + '0';
		ft_putchar_fd(c, fd);
		n = n - (n / d) * d;
		d = d / 10;
	}
}
