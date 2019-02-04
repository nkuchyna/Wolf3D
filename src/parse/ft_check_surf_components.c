/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_surf_components.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:58:24 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/06 10:58:40 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_check_path(char *str)
{
	SDL_Surface		*text;

	if (!(text = SDL_LoadBMP(str)))
		return (-1);
	SDL_FreeSurface(text);
	return (0);
}

static int	ft_check_nbr(char *str)
{
	int		i;
	int		len;
	int		nbr;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if ((str[i] == 0 && i == 0 && len != 1)
		|| (str[i] < '0' && str[i] > '9'))
			return (-1);
	}
	nbr = ft_atoi(str);
	if (i > 3 || (nbr < 0 && nbr > 255))
		return (-1);
	return (1);
}

static int	ft_check_vector(char *str)
{
	int		len;
	int		i;
	char	**vect_comp;
	char	*new_str;
	char	*tmp;

	len = ft_strlen(str);
	if (str[0] != '{' || str[len - 1] != '}')
		return (-1);
	i = 0;
	tmp = ft_strdup(str);
	new_str = ft_strsub(tmp, 1, len - 2);
	ft_strdel(&tmp);
	vect_comp = ft_strsplit(new_str, ',');
	while (vect_comp[i])
	{
		if (ft_check_nbr(vect_comp[i]) != 1)
			break ;
		i++;
	}
	ft_free_char_array(vect_comp);
	ft_strdel(&new_str);
	if (i != 3)
		return (-1);
	return (0);
}

static int	ft_print_surf_parce_error(int error, int str_nbr)
{
	ft_putstr("string - ");
	ft_putnbr(str_nbr);
	if (error == -1)
		ft_putendl(" WARNING: the textures or colors were indicated\
incorrectly!");
	if (error == WRONG_PATH)
		ft_putendl(" WARNING: the path of texture is incorrect or color \
with default structure! Example: {1,2,3}. The color's componets must be \
in range from 0 to 255.");
	if (error == ERROR_DESCR)
		ft_putendl(" WARNING: please indicate color or path of the texture!");
	return (-1);
}

int			ft_check_surf_components(char *line, int str_nbr)
{
	char	**comp_array;
	int		i;

	i = 0;
	comp_array = ft_strsplit(line, ' ');
	while (comp_array[i])
	{
		if ((i == 0 && ft_atoi(comp_array[i]) == 0)
		|| (i == 1 && ft_strcmp(comp_array[i], "-")))
			ft_print_surf_parce_error(-1, str_nbr);
		if (i == 2 && ft_check_path(comp_array[i]) == -1)
		{
			if (ft_check_vector(comp_array[i]) == -1)
			{
				ft_print_surf_parce_error(WRONG_PATH, str_nbr);
				break ;
			}
		}
		i++;
	}
	ft_free_char_array(comp_array);
	if (i < 3)
		return (ft_print_surf_parce_error(ERROR_DESCR, str_nbr));
	return (0);
}
