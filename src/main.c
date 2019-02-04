/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:17:49 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/08 18:10:28 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_exit(t_sd sd, int surf_nbr)
{
	int		n;

	n = -1;
	if (sd.screen != NULL)
		SDL_FreeSurface(sd.screen);
	if (sd.window != NULL)
		SDL_DestroyWindow(sd.window);
	if (sd.levels)
		while (++n < 3 && sd.levels[n].map)
			ft_delete_int_array(sd.levels[n].map, sd.levels[n].h);
	if (sd.surf != NULL)
		ft_free_surf_array(sd.surf, surf_nbr);
	if (sd.music != NULL)
		Mix_FreeMusic(sd.music);
	if (sd.sound1 != NULL)
		Mix_FreeChunk(sd.sound1);
	if (sd.sound2 != NULL)
		Mix_FreeChunk(sd.sound2);
	Mix_CloseAudio();
	system("leaks wolf3d");
	exit(1);
}

static void	ft_print_error_source(int ret)
{
	if (ret == INIT_LIB_ERROR)
		ft_putendl("Error: SDL library initialization error!");
	else if (ret == NO_BLOCK_ERROR)
		ft_putendl("Error: The map must have at least 3X3 size!");
	else if (ret == BLOCK_IND_ERROR)
		ft_putendl("Error: Blocks must be only positive integer!");
	else if (ret == SCENE_IND_ERROR)
		ft_putendl("Error: Wrong indication of the scene!");
	else if (ret == ARR_ALLOC_ERROR)
		ft_putendl("Error: The array has not been allocated!");
}

static int	ft_open_levels_source(int *fd)
{
	int		ret;

	ret = 0;
	if ((fd[0] = open("maps/map1", O_RDWR)) < 0)
		ret = -1;
	else if ((fd[1] = open("maps/map2", O_RDWR)) < 0)
	{
		close(fd[0]);
		ret = -1;
	}
	else if ((fd[2] = open("maps/map3", O_RDWR)) < 0)
	{
		close(fd[0]);
		close(fd[1]);
		ret = -1;
	}
	if (ret == -1)
		ft_putendl(strerror(errno));
	return (ret);
}

int			main(int argc, char **argv)
{
	int			ret;
	int			fd[3];
	t_sd		sd;

	ret = 0;
	if (argc != 1)
	{
		ft_putstr("usage");
		ft_putendl(argv[0]);
		return (1);
	}
	if (ft_open_levels_source(fd) == -1)
		return (-1);
	if (ft_init_sdl(&sd) == 1 || (ret = ft_parse_scene(fd, &sd)) < 0)
	{
		ft_print_error_source(ret);
		ft_exit(sd, sd.surf_nbr);
	}
	if (close(fd[0]) < 0 || close(fd[1]) < 0 || close(fd[2]) < 0)
		ft_putendl(strerror(errno));
	if (sd.cover && sd.fire)
		ft_load_cover(&sd);
	ft_loop(&sd);
	return (0);
}
