/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:06:45 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/04 19:09:56 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		k;
	size_t		len_s;
	size_t		len_d;

	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	k = 0;
	i = len_d;
	if (size < (len_d + 1))
		return (len_s + size);
	while (i < (size - 1))
		dst[i++] = src[k++];
	dst[i] = '\0';
	return (len_d + len_s);
}
