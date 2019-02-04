/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createarray_charx2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:26:51 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 16:35:32 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_createarray_charx2(int x, int y, char filler)
{
	char	**new_array;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (x <= 0 || y <= 0 || !filler)
		return (NULL);
	new_array = (char**)malloc(sizeof(char*) * (x + 1));
	while (i < x)
	{
		k = 0;
		new_array[i] = ft_strnew(y);
		while (k < y)
		{
			new_array[i][k] = filler;
			k++;
		}
		new_array[i][k] = '\0';
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
