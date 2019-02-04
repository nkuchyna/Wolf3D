/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 19:28:12 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/06 19:51:05 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_keydown_event(t_sd *sd, const Uint8 *kb_state)
{
	if (kb_state[SDL_SCANCODE_UP] && sd->event.key.state == SDL_PRESSED)
		sd->go = 1;
	if (kb_state[SDL_SCANCODE_DOWN] && sd->event.key.state == SDL_PRESSED)
		sd->go = 2;
	if (kb_state[SDL_SCANCODE_RIGHT] && sd->event.key.state == SDL_PRESSED)
		sd->rotate = 1;
	if (kb_state[SDL_SCANCODE_LEFT] && sd->event.key.state == SDL_PRESSED)
		sd->rotate = 2;
	if (kb_state[SDL_SCANCODE_T])
		sd->side_text = 1;
	if (kb_state[SDL_SCANCODE_Y])
		sd->side_text = 0;
}

static void	ft_keyup_event(t_sd *sd)
{
	if ((sd->event.key.keysym.sym == SDLK_RIGHT
	|| sd->event.key.keysym.sym == SDLK_LEFT)
	&& sd->event.key.state == SDL_RELEASED)
		sd->rotate = 0;
	else if ((sd->event.key.keysym.sym == SDLK_UP
	|| sd->event.key.keysym.sym == SDLK_DOWN)
	&& sd->event.key.state == SDL_RELEASED)
		sd->go = 0;
}

static int	ft_load_finish(t_sd *sd)
{
	Mix_PlayChannel(1, sd->win_sound, 0);
	while (sd->pgm_run)
	{
		while (SDL_PollEvent(&sd->event) == 1)
		{
			if (sd->event.type == SDL_QUIT || (sd->event.type == SDL_KEYDOWN
			&& sd->event.key.keysym.sym == SDLK_ESCAPE))
				sd->pgm_run = 0;
		}
		SDL_memset(sd->screen->pixels, 0, sd->screen->h * sd->screen->pitch);
		ft_print_img(sd->finish, sd->screen, 0, 0);
		SDL_UpdateWindowSurface(sd->window);
	}
	return (0);
}

static int	ft_manage_display(t_sd *sd, int *menu)
{
	SDL_memset(sd->screen->pixels, 0, sd->screen->h * sd->screen->pitch);
	if (!(*menu))
	{
		if (sd->go > 0 || sd->rotate > 0)
			ft_manage_movements(sd, &sd->levels[sd->l_nbr]);
		if (sd->l_nbr == 3)
		{
			Mix_PlayChannel(1, sd->level_sound, 0);
			if (!ft_load_finish(sd))
				return (0);
		}
		ft_raycasting(sd);
		SDL_BlitSurface(sd->l_text, NULL, sd->screen, &sd->text_place);
	}
	else
	{
		if (ft_load_cover(sd) == 0)
			sd->pgm_run = 0;
		else
			*menu = 0;
	}
	SDL_UpdateWindowSurface(sd->window);
	return (1);
}

void		ft_loop(t_sd *sd)
{
	const Uint8	*kb_state;
	int			menu;

	kb_state = SDL_GetKeyboardState(NULL);
	menu = 0;
	while (sd->pgm_run)
	{
		while (SDL_PollEvent(&sd->event))
		{
			if (sd->event.type == SDL_QUIT || (sd->event.type == SDL_KEYDOWN
			&& sd->event.key.keysym.sym == SDLK_ESCAPE))
				ft_exit(*sd, sd->surf_nbr);
			if (sd->event.type == SDL_KEYDOWN)
				ft_keydown_event(sd, kb_state);
			if (sd->event.type == SDL_KEYUP)
				ft_keyup_event(sd);
			if (kb_state[SDL_SCANCODE_M])
				menu = 1;
		}
		if (!(ft_manage_display(sd, &menu)))
			break ;
	}
}
