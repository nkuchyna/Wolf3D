/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:24:07 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/03 21:51:18 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (n == 0 || (s1 == NULL && s2 == NULL))
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (i < (n - 1) && str1[i] != '\0' && s2[i] != '\0'
			&& str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
