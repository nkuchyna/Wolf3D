/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:43:39 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/28 20:52:22 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*m;

	p = (unsigned char*)s1;
	m = (unsigned char*)s2;
	while ((p || m) && n > 0)
	{
		if (*p != *m)
			return (*p - *m);
		p++;
		m++;
		n--;
	}
	return (0);
}
