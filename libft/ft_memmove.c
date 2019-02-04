/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:02:20 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/03 19:37:24 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p;
	const char	*m;

	p = (char*)dst;
	m = (char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst <= src || dst >= (src + len))
	{
		while (len > 0)
		{
			*p++ = *m++;
			len--;
		}
		return (dst);
	}
	m = m + len - 1;
	p = p + len - 1;
	while (len > 0)
	{
		*p-- = *m--;
		len--;
	}
	return (dst);
}
