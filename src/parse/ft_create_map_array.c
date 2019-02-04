/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:10:21 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/04 11:11:18 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	*ft_fill_map_array_str(t_level *level, char *str, int i)
{
	char	**str_el_array;
	int		*map_array_str;
	int		j;

	j = 0;
	str_el_array = ft_strsplit_new(str);
	map_array_str = malloc(sizeof(int) * level->w);
	while (j < level->w && str_el_array[j] != NULL)
	{
		map_array_str[j] = abs(ft_atoi(str_el_array[j]));
		if (!(ft_strcmp(str_el_array[j], "p")))
			level->pos = (t_vector){j + 0.5, i + 0.5};
		if (!(ft_strcmp(str_el_array[j], "e")))
		{
			level->exit = (t_vector){j, i};
			map_array_str[j] = 42;
		}
		if (((i == 0 || i == level->h - 1) && map_array_str[j] == 0)
		|| ((j == 0 || j == level->w - 1) && map_array_str[j] == 0))
			map_array_str[j] = 1;
		j++;
	}
	ft_free_char_array(str_el_array);
	return (map_array_str);
}

int			**ft_create_map_array(t_level *level, char *str_scene)
{
	int		**map;
	char	**map_str;
	int		i;

	i = 0;
	map_str = ft_strsplit(str_scene, '\n');
	ft_strdel(&str_scene);
	if (!map_str)
		return (NULL);
	map = malloc(sizeof(int*) * level->h);
	while (i < level->h && map_str[i])
	{
		map[i] = ft_fill_map_array_str(level, map_str[i], i);
		i++;
	}
	ft_free_char_array(map_str);
	return (map);
}
