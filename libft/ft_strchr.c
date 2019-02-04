/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:01:08 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/29 15:42:59 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		len;

	str = (char*)s;
	len = ft_strlen(str);
	while (len > 0 && *str != (char)c)
	{
		str++;
		len--;
	}
	if (*str == '\0' && (char)c != '\0')
		return (NULL);
	return (str);
}
