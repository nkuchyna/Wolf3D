/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:51:34 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/01 20:59:29 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str_empty(void)
{
	char		*str;

	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	return (str);
}

char			*ft_strnew(size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	if (size == 0)
		return (ft_str_empty());
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < (size + 1))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
