/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:49:15 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 18:56:27 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_sort_int_array(int *array, int array_size)
{
	int			i;
	int			temp;
	int			count;

	temp = 0;
	if (array == NULL || array_size == 0)
		return (NULL);
	count = array_size - 1;
	while (count > 0)
	{
		i = 0;
		while (i < (array_size - 1))
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
		count--;
	}
	return (array);
}
