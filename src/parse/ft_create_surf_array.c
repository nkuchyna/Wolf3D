/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_surf_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:08:32 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/16 21:08:49 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_color	ft_read_and_fill_color(char *str)
{
	t_color		color;
	char		**color_comp;
	char		*color_str;
	int			i;

	color = (t_color){120, 120, 120};
	i = -1;
	if (!str)
		return (color);
	color_str = ft_strsub(str, 1, ft_strlen(str) - 2);
	color_comp = ft_strsplit(color_str, ',');
	while (++i < 3 && color_comp[i])
		color[i] = ft_atoi(color_comp[i]);
	ft_strdel(&color_str);
	ft_free_char_array(color_comp);
	return (color);
}

static t_surf	ft_fill_surf_arr(char *str)
{
	t_surf		surf;
	char		**str_comp;

	if (!(str_comp = ft_strsplit_new(str)))
	{
		surf.id = -1;
		return (surf);
	}
	surf.id = ft_atoi(str_comp[0]);
	if (!(surf.text = SDL_LoadBMP(str_comp[2])))
		surf.color = ft_read_and_fill_color(str_comp[2]);
	else
		surf.color = (t_color){100, 100, 100};
	ft_free_char_array(str_comp);
	return (surf);
}

static t_surf	*ft_create_and_fill_surf_arr(int nbr, char *str)
{
	t_surf	*surfaces;
	char	**surf_str;
	char	*tmp;
	int		i;

	i = -1;
	surfaces = NULL;
	tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
	ft_strdel(&str);
	str = tmp;
	if (!(surfaces = (t_surf*)malloc(nbr * sizeof(t_surf))))
		return (NULL);
	surf_str = ft_strsplit(str, '\n');
	while (++i < nbr && surf_str[i] != NULL)
		surfaces[i] = ft_fill_surf_arr(surf_str[i]);
	ft_free_char_array(surf_str);
	ft_strdel(&str);
	return (surfaces);
}

static t_surf	*ft_clear_exit(char **str_dscr)
{
	ft_strdel(str_dscr);
	return (NULL);
}

t_surf			*ft_create_surf_array(int fd, int *surf_nbr)
{
	t_surf	*surfaces;
	char	*str_dscr;
	char	*line;
	int		str_nbr;

	if (!(str_dscr = ft_strdup(" ")))
		return (NULL);
	str_nbr = 0;
	while (get_next_line(fd, &line) == 1)
	{
		str_nbr++;
		if (ft_strcmp(line, "\0") && !(ft_check_surf_components(line, str_nbr)))
		{
			line = ft_strjoin(line, ft_strdup("\n"));
			str_dscr = ft_strjoin(str_dscr, line);
			(*surf_nbr)++;
		}
		else
			ft_strdel(&line);
	}
	if (*surf_nbr == 0 || str_dscr == NULL)
		return (ft_clear_exit(&str_dscr));
	surfaces = ft_create_and_fill_surf_arr(*surf_nbr, str_dscr);
	return (surfaces);
}
