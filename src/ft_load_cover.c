/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_cover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:37:49 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/15 12:38:06 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_print_img(SDL_Surface *img, SDL_Surface *screen, int dx, int dy)
{
	t_color	color;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH && x < img->w)
	{
		y = 0;
		while (y < H && y < img->h)
		{
			color = ft_color_from_texture(x, y, img);
			ft_putpixel(x + dx, y + dy, screen, color);
			y++;
		}
		x++;
	}
}

static int	ft_move_icon(int y, int *counter, const Uint8 *kb_state)
{
	if (*counter < 3 && kb_state[SDL_SCANCODE_DOWN])
	{
		y += 45;
		(*counter)++;
	}
	else if (*counter > 1 && kb_state[SDL_SCANCODE_UP])
	{
		y -= 45;
		(*counter)--;
	}
	return (y);
}

static void	ft_mng_cover_display(t_sd *sd, int counter, int *cover, int *info)
{
	if (counter == 1)
		*cover = 0;
	else if (counter == 2 && *info != 1)
		*info = 1;
	else if (counter == 2 && *info == 1)
		*info = 0;
	else if (counter == 3)
		ft_exit(*sd, sd->surf_nbr);
}

static void	ft_fill_screen(t_sd *sd, t_vector xy, int info)
{
	SDL_memset(sd->screen->pixels, 0, sd->screen->h * sd->screen->pitch);
	if (!info)
	{
		ft_print_img(sd->cover, sd->screen, 0, 0);
		ft_print_img(sd->fire, sd->screen, xy[0], xy[1]);
	}
	else
		ft_print_img(sd->info, sd->screen, 0, 0);
	SDL_UpdateWindowSurface(sd->window);
}

int			ft_load_cover(t_sd *sd)
{
	const Uint8 *kb_state;
	t_vector	xy;
	int			cover;
	int			counter;
	int			info;

	ft_init(&kb_state, &cover, &counter, &info);
	xy = (t_vector){240, 105};
	while (sd->pgm_run && cover)
	{
		while (SDL_PollEvent(&sd->event) == 1)
		{
			if (sd->event.type == SDL_QUIT || (sd->event.type == SDL_KEYDOWN
			&& sd->event.key.keysym.sym == SDLK_ESCAPE))
				sd->pgm_run = 0;
			if (kb_state[SDL_SCANCODE_M])
				break ;
			if (kb_state[SDL_SCANCODE_DOWN] || kb_state[SDL_SCANCODE_UP])
				xy[1] = ft_move_icon(xy[1], &counter, kb_state);
			if (counter && kb_state[SDL_SCANCODE_RETURN])
				ft_mng_cover_display(sd, counter, &cover, &info);
		}
		ft_fill_screen(sd, xy, info);
	}
	return (1);
}
