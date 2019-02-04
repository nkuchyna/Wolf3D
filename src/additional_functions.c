/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:19:18 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/09 12:19:24 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_putpixel(int x, int y, SDL_Surface *screen, t_color color)
{
	unsigned char	*str;
	int				i;

	str = screen->pixels;
	i = x * screen->format->BytesPerPixel + y * screen->pitch;
	if (x < WIDTH && y < H)
	{
		str[i] = (int)color[2];
		str[++i] = (int)color[1];
		str[++i] = (int)color[0];
	}
}

t_color	ft_color_from_texture(int t_x, int t_y, SDL_Surface *text)
{
	int				i;
	unsigned char	*str;
	t_color			color;

	str = (unsigned char*)text->pixels;
	i = t_x * text->format->BytesPerPixel + t_y * text->pitch;
	color[2] = (double)str[i];
	color[1] = (double)str[++i];
	color[0] = (double)str[++i];
	return (color);
}

int		ft_check_map(t_vector map_pos, int **map, int width, int height)
{
	int		ret;

	ret = 0;
	if (map_pos[0] > width || map_pos[1] > height
	|| map_pos[0] < 0 || map_pos[1] < 0)
		return (ret);
	ret = map[(int)map_pos[1]][(int)map_pos[0]];
	return (ret);
}

int		ft_count_elements(char *str)
{
	int			nb;
	int			i;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == 'p' || str[i] == 'e')
				i++;
			else
				return (-1);
		}
		if (str[i] == ' ' || str[i] == '\t'
		|| (str[i] == '\0' && str[i - 1] != ' ' && str[i - 1] != '\t'))
			nb++;
	}
	return (nb);
}
