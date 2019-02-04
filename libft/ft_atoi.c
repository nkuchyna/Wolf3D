/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:07:14 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 16:27:28 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_sub_over_max_atoi(unsigned long int nb, int *flag, int k)
{
	if (nb > 922337203854775807 && k != -1)
		(*flag) = -1;
	if (nb > 9223372036854775807 && k == -1)
		(*flag) = 0;
}

static int		ft_sub_atoi(char *str, int *k, int *flag)
{
	long long int			i;
	unsigned long int		nb;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
			i++;
		if (str[i] == '-')
			(*k) = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		{
			nb = nb * 10 + (str[i++] - '0');
			ft_sub_over_max_atoi(nb, &(*flag), (*k));
		}
		return (nb);
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	int								k;
	unsigned long int				nb;
	unsigned long long int			c;
	int								flag;
	char							*str_new;

	str_new = (char*)str;
	k = 1;
	nb = 0;
	c = 0;
	flag = 1;
	nb = ft_sub_atoi(str_new, &k, &flag);
	if (flag == -1)
		return (-1);
	if (flag == 0)
		return (0);
	return (nb * k);
}
