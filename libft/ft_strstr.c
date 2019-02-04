/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:22:57 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/01 13:32:24 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		k;
	size_t		a;

	i = 0;
	a = 0;
	k = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] != '\0' && little[k] != '\0')
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
	if (k == ft_strlen(little))
		return ((char*)&big[i - k]);
	return (NULL);
}
