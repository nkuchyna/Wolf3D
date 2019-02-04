/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:11:03 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/29 20:47:16 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		k;
	char		*str;

	str = (char*)s2;
	i = ft_strlen(s1);
	k = 0;
	while (k < n && str[k] != '\0')
	{
		s1[i] = str[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}
