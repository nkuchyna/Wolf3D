/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:58:05 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/29 15:45:21 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		k;
	size_t		a;

	i = 0;
	a = 0;
	k = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] != '\0' && little[k] != '\0' && i < len)
	{
		if (little[k] == big[i])
		{
			i++;
			k++;
		}
		else
		{
			k = 0;
			i = ++a;
		}
	}
	if (little[k] == '\0')
		return ((char*)&big[i - k]);
	return (NULL);
}
