/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_torch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:02:59 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/13 17:04:11 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static SDL_Surface	*ft_define_torch_texture(t_sd *sd, SDL_Surface **torch)
{
	SDL_Surface	*text;

	text = NULL;
	if (sd->time % 3 == 0 && torch[0])
		text = torch[0];
	else if (sd->time % 5 == 0 && torch[1])
		text = torch[1];
	else if (sd->time % 7 == 0 && torch[2])
		text = torch[2];
	else if (sd->time % 11 == 0 && torch[3])
		text = torch[3];
	else if (sd->time % 13 == 0 && torch[4])
		text = torch[4];
	else if (sd->time % 17 == 0 && torch[5])
		text = torch[5];
	else if (sd->time % 19 == 0 && torch[6])
		text = torch[6];
	else if (torch[7])
		text = torch[7];
	return (text);
}

void				ft_draw_torch(SDL_Surface **torch, t_sd *sd)
{
	int			x;
	int			y;
	t_color		color;
	SDL_Surface	*text;

	sd->time = clock() / (CLOCKS_PER_SEC / 5);
	if (!(text = ft_define_torch_texture(sd, torch)))
		return ;
	y = 0;
	while (y < text->h)
	{
		x = 0;
		while (x < text->w)
		{
			color = ft_color_from_texture(x, y, text);
			if (color[0] != 255 && color[1] != 255 && color[2] != 255)
				ft_putpixel(x + 290, y + 250, sd->screen, color);
			x++;
		}
		y++;
	}
}
