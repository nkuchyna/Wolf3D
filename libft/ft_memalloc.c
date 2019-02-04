/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:22:16 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/03/27 19:25:04 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	if (size > 0)
	{
		p = (char*)malloc(sizeof(char) * size);
		if (p == NULL)
			return (NULL);
		while (i < size)
		{
			p[i] = '\0';
			i++;
		}
	}
	return (p);
}
