/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:23:38 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/30 14:07:22 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		a;
	int		l;
	char	*str;

	str = (char*)s;
	i = ft_strlen(str);
	a = 0;
	l = 0;
	while (i > 0 && str[i] != (char)c)
	{
		i--;
		a++;
	}
	if (str[i] == str[0] && str[0] != (char)c)
		return (NULL);
	l = ft_strlen(str) - a;
	while (l > 0)
	{
		str++;
		l--;
	}
	return (str);
}
