/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:29:55 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/06 11:30:17 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_calc_t_x(t_sd *sd, t_surf *surf, int side, double wall_x)
{
	int			t_x;

	t_x = (int)(wall_x * (double)surf->text->w);
	if ((side == 1 || side == 2) && sd->ray_dir[0] > 0)
		t_x = surf->text->w - t_x - 1;
	else if ((side == 3 && side == 4) && sd->ray_dir[1] < 0)
		t_x = surf->text->w - t_x - 1;
	return (t_x);
}

static int	ft_calc_t_y(t_sd *sd, t_surf *surf, int y)
{
	int			d;
	int			t_y;

	d = y * 512 - H * 256 + sd->line_height * 256;
	t_y = ((d * surf->text->h) / sd->line_height) / 512;
	t_y = t_y % surf->text->h;
	return (t_y);
}

t_color		ft_text_by_compass_point(t_sd *sd, double y, int side)
{
	int			t_x;
	int			t_y;

	if (sd->surf[side - 1].text != NULL)
	{
		t_x = ft_calc_t_x(sd, &sd->surf[side - 1], side, sd->wall_x);
		t_y = ft_calc_t_y(sd, &sd->surf[side - 1], y);
		return (ft_color_from_texture(t_x, t_y, sd->surf[side - 1].text));
	}
	else
		return ((sd->surf[side - 1].color));
}

t_color		ft_apply_wall_text(t_sd *sd, double y, t_surf *surf, int side)
{
	int			t_x;
	int			t_y;
	t_color		color;

	color = surf->color;
	if (sd->side_text == 1)
	{
		if (sd->surf_nbr >= 4)
			return (ft_text_by_compass_point(sd, y, side));
		if (side == 1)
			return ((t_color){255, 0, 0});
		else if (side == 2)
			return ((t_color){0, 255, 0});
		else if (side == 3)
			return ((t_color){0, 0, 255});
		else
			return ((t_color){255, 255, 0});
	}
	if (surf && surf->text != NULL && sd->side_text != 1)
	{
		t_x = ft_calc_t_x(sd, surf, side, sd->wall_x);
		t_y = ft_calc_t_y(sd, surf, y);
		color = ft_color_from_texture(t_x, t_y, surf->text);
	}
	return (color);
}

t_color		ft_apply_text(t_sd *sd, double y, t_surf *surf, t_vector fl_w)
{
	t_vector	current_floor;
	double		current_dist;
	double		weight;
	t_vector	t;
	t_color		color;

	if (surf->text != NULL)
	{
		current_dist = (double)H / (2 * y - H);
		weight = current_dist / sd->wall_dist;
		current_floor[0] = weight * fl_w[0]
							+ (1 - weight) * sd->levels[sd->l_nbr].pos[0];
		current_floor[1] = weight * fl_w[1]
							+ (1 - weight) * sd->levels[sd->l_nbr].pos[1];
		t[0] = (int)(current_floor[0] * surf->text->w) % surf->text->w;
		t[1] = (int)(current_floor[1] * surf->text->h) % surf->text->h;
		color = ft_color_from_texture(t[0], t[1], surf->text);
		if (current_dist > 1)
			color = MULT_C(color, (double)1 / current_dist);
		return (color);
	}
	else
		return (surf->color);
}
