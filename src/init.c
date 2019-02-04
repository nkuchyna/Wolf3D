/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:39:42 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/13 16:41:39 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_music(t_sd *sd)
{
	int		audio_rate;
	Uint16	audio_format;
	int		audio_chan;
	int		audio_buffers;

	audio_rate = 22050;
	audio_format = MIX_DEFAULT_FORMAT;
	audio_chan = 2;
	audio_buffers = 4096;
	if (Mix_OpenAudio(audio_rate, audio_format, audio_chan, audio_buffers) != 0
	|| !(sd->music = Mix_LoadMUS("resources/sound.wav"))
	|| !(sd->sound1 = Mix_LoadWAV("resources/step_water.wav"))
	|| !(sd->level_sound = Mix_LoadWAV("resources/level.wav"))
	|| !(sd->sound2 = Mix_LoadWAV("resources/step_wood.wav"))
	|| !(sd->win_sound = Mix_LoadWAV("resources/win.wav")))
		ft_putendl("The soundtrack was not opened!");
}

int		ft_init_sdl(t_sd *sd)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	if (!(sd->window = SDL_CreateWindow("wolf3d", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIDTH, H, SDL_WINDOW_SHOWN)))
		return (1);
	if (!(sd->screen = SDL_GetWindowSurface(sd->window)) || TTF_Init() < 0)
		return (1);
	ft_init_music(sd);
	if (Mix_PlayMusic(sd->music, -1) == -1)
		return (1);
	sd->pgm_run = 1;
	sd->surf = NULL;
	sd->side_text = 0;
	sd->torch = NULL;
	sd->time = 0;
	sd->color = (t_color){100, 100, 100};
	sd->text_col.r = 255;
	sd->text_col.g = 255;
	sd->text_col.b = 255;
	if (!(sd->font = TTF_OpenFont("resources/OpenSans.ttf", 20)))
	{
		ft_putendl("Error: There is not such font!");
		exit(1);
	}
	SDL_memset(sd->screen->pixels, 0, sd->screen->h * sd->screen->pitch);
	return (0);
}

void	ft_init_levels_and_covers(t_level *levels, t_sd *sd)
{
	int			n;

	n = -1;
	sd->l_nbr = 0;
	while (++n < 3)
	{
		levels[n].map = NULL;
		levels[n].h = 1;
		levels[n].w = 0;
		levels[n].exit = (t_vector){0, 0};
		levels[0].floor_surf.color = (t_color){150, 150, 150};
	}
	levels[0].floor_surf.text = SDL_LoadBMP("textures/water.bmp");
	levels[1].floor_surf.text = SDL_LoadBMP("textures/ceil1.bmp");
	levels[2].floor_surf.text = SDL_LoadBMP("textures/ceil1.bmp");
	sd->cover = SDL_LoadBMP("textures/cover.bmp");
	sd->fire = SDL_LoadBMP("textures/fire.bmp");
	sd->info = SDL_LoadBMP("textures/info.bmp");
	sd->finish = SDL_LoadBMP("textures/finish.bmp");
	sd->l_text = TTF_RenderText_Solid(sd->font, "LEVEL 1", sd->text_col);
	sd->text_place.x = 550;
	sd->text_place.y = 20;
	sd->text_place.h = 50;
	sd->text_place.w = 50;
}

void	ft_init_sd(t_sd *sd)
{
	ft_init_levels_and_covers(sd->levels, sd);
	sd->dir = NORM(((t_vector){1, 0}));
	sd->plane[0] = 0;
	sd->plane[1] = 0.66;
	sd->surf_nbr = 0;
	sd->go = 0;
	sd->rotate = 0;
	sd->ceiling_surf.text = SDL_LoadBMP("textures/ceil1.bmp");
	sd->exit_surf.text = SDL_LoadBMP("textures/doors.bmp");
	sd->torch = malloc(sizeof(SDL_Surface *) * 9);
	if (sd->torch)
	{
		sd->torch[0] = SDL_LoadBMP("textures/torch/1.bmp");
		sd->torch[1] = SDL_LoadBMP("textures/torch/2.bmp");
		sd->torch[2] = SDL_LoadBMP("textures/torch/3.bmp");
		sd->torch[3] = SDL_LoadBMP("textures/torch/4.bmp");
		sd->torch[4] = SDL_LoadBMP("textures/torch/5.bmp");
		sd->torch[5] = SDL_LoadBMP("textures/torch/6.bmp");
		sd->torch[6] = SDL_LoadBMP("textures/torch/7.bmp");
		sd->torch[7] = SDL_LoadBMP("textures/torch/8.bmp");
		sd->torch[8] = SDL_LoadBMP("textures/torch/9.bmp");
	}
	sd->ceiling_surf.color = (t_color){150, 150, 150};
	sd->exit_surf.color = (t_color){150, 150, 150};
}

void	ft_init(const Uint8 **kb_state, int *cover, int *c, int *info)
{
	*kb_state = SDL_GetKeyboardState(NULL);
	*cover = 1;
	*c = 1;
	*info = 0;
}
