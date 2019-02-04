/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 19:53:57 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/11 19:54:11 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_clear_exit(char **str_scene, char **line)
{
	ft_strdel(str_scene);
	ft_strdel(line);
	return (-1);
}

static int	ft_check_content(int width, int *height, char **scene, int fd)
{
	char	*line;
	int		count;
	int		player;

	line = NULL;
	count = 0;
	player = 0;
	*scene = ft_strjoin(*scene, ft_strdup("\n"));
	while (get_next_line(fd, &line) == 1 && ft_strcmp(line, "*TEXTURE/COLOR*"))
	{
		if (ft_strcmp(line, "\0"))
		{
			if (ft_strstr(line, "p") || ft_strstr(line, "P"))
				player++;
			if (ft_count_elements(line) != width || player > 1)
				return (ft_clear_exit(scene, &line));
			*scene = ft_strjoin(*scene, ft_strjoin(line, ft_strdup("\n")));
			line = NULL;
			(*height)++;
		}
		else
			ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}

static int	ft_check_map_gen(int *width, int *height, int fd, char **str_scene)
{
	if (!(*width = ft_count_elements(*str_scene)))
		return (BLOCK_IND_ERROR);
	if (ft_check_content(*width, &(*height), &(*str_scene), fd) == -1 ||
		*width < 3 || *height < 3)
	{
		ft_strdel(&(*str_scene));
		return (SCENE_IND_ERROR);
	}
	return (0);
}

static int	ft_read_levels(t_level *level, int fd)
{
	char		*str_scene;
	int			ret;

	ret = 0;
	str_scene = NULL;
	while (1)
	{
		get_next_line(fd, &str_scene);
		if (str_scene == NULL)
			return (NO_BLOCK_ERROR);
		if (ft_strcmp(str_scene, "\0") != 0)
			break ;
		else
			ft_strdel(&str_scene);
	}
	if ((ret = ft_check_map_gen(&level->w, &level->h, fd, &str_scene)) != 0)
		return (ret);
	if (!(level->map = ft_create_map_array(level, str_scene)))
		return (ARR_ALLOC_ERROR);
	if (ft_check_map(level->pos, level->map, level->w, level->h) != 0 ||
		ft_check_map(level->exit, level->map, level->w + 1, level->h + 1) != 42)
		return (SCENE_IND_ERROR);
	return (ret);
}

int			ft_parse_scene(int *fd, t_sd *sd)
{
	int			ret;
	int			level_nbr;

	level_nbr = -1;
	if (!(sd->levels = malloc(sizeof(t_level) * 3)))
		return (ARR_ALLOC_ERROR);
	ft_init_sd(sd);
	while (++level_nbr < 3)
		if ((ret = ft_read_levels(&sd->levels[level_nbr], fd[level_nbr])) != 0)
			return (ret);
	sd->surf = ft_create_surf_array(fd[0], &sd->surf_nbr);
	return (0);
}
