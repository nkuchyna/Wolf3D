/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:28:45 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/29 20:17:19 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_itoa(int n, int *d)
{
	int		a;

	a = 1;
	if (n == 0)
		return (2);
	if ((n >= -2147483648 && n < -999999999) ||
		(n <= 2147483647 && n > 999999999))
	{
		(*d) = 1000000000;
		return (10);
	}
	while (n / (*d) != 0)
	{
		(*d) *= 10;
		a++;
	}
	if (n != 0)
		(*d) = (*d) / 10;
	return (a);
}

static char		*ft_fill_itoa(int d, char *str, int i, int n)
{
	while (d > 0)
	{
		str[i++] = n / d + '0';
		n = n - (n / d) * d;
		d = d / 10;
	}
	str[i] = '\0';
	return (str);
}

static char		*ft_sub_itoa(int n, int c)
{
	int		d;
	int		i;
	char	*str;

	d = 1;
	i = 0;
	str = ft_strnew(ft_count_itoa(n, &d) + c - 1);
	if (str == NULL)
		return (NULL);
	if (c == 1)
	{
		str[i++] = '-';
		if (n == -2147483648)
		{
			str[i++] = '2';
			n = 147483648;
			d = d / 10;
		}
		else
			n = -n;
	}
	str = ft_fill_itoa(d, str, i, n);
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n < 0 && n >= -2147483648)
		str = ft_sub_itoa(n, 1);
	else if (n >= 0 && n <= 2147483647)
		str = ft_sub_itoa(n, 0);
	else
		return (NULL);
	return (str);
}
