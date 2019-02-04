/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:48:18 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/01 13:33:09 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;

	i = start;
	k = 0;
	if (s == NULL || (size_t)start > ft_strlen(s))
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (len > 0)
	{
		str[k] = s[i];
		k++;
		i++;
		len--;
	}
	str[k] = '\0';
	return (str);
}
