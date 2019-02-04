/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray_charx2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:19:38 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 16:56:29 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarray_charx2(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
