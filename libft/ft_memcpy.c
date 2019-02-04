/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:11:00 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/03 19:28:21 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*p;
	unsigned char			*m;

	p = (unsigned char*)dst;
	m = (unsigned char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*p++ = *m++;
		n--;
	}
	return ((void*)dst);
}
