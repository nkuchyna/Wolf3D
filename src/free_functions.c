/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 18:02:27 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/16 18:02:48 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_delete_int_array(int **array, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	ft_free_surf_array(t_surf *surf, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		SDL_FreeSurface(surf[i].text);
	free(surf);
}
