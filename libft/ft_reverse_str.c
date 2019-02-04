/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:54:26 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/01 13:42:59 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_reverse_str(char *str)
{
	int		i;
	int		m;
	int		l;
	char	temp;

	i = 0;
	if (str == NULL)
		return (NULL);
	l = ft_strlen(str);
	m = l - 1;
	while (i < l / 2)
	{
		temp = str[i];
		str[i] = str[m];
		str[m] = temp;
		i++;
		m--;
	}
	return (str);
}
