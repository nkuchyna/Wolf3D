/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:14:26 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/31 12:14:59 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_char_array(char **array)
{
	int			k;

	k = 0;
	while (array[k] != NULL)
	{
		ft_strdel(&array[k]);
		k++;
	}
	free(array);
	array = NULL;
}
