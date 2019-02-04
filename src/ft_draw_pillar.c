/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pillar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 18:04:29 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/12 18:04:42 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vector	ft_define_floor_wall_coord(int side, t_sd *sd, double wall_x)
{
	t_vector	floor_wall;

	if (side == 1)
	{
		floor_wall[0] = sd->map_pos[0];
		floor_wall[1] = sd->map_pos[1] + wall_x;
	}
	else if (side == 2)
	{
		floor_wall[0] = sd->map_pos[0] + 1;
		floor_wall[1] = sd->map_pos[1] + wall_x;
	}
	else if (side == 3)
	{
		floor_wall[0] = sd->map_pos[0] + wall_x;
		floor_wall[1] = sd->map_pos[1];
	}
	else
	{
		floor_wall[0] = sd->map_pos[0] + wall_x;
		floor_wall[1] = sd->map_pos[1] + 1;
	}
	if (sd->draw[1] < 0)
		sd->draw[1] = H;
	return (floor_wall);
}

t_vector	ft_define_draw_extr(t_sd *sd, int side, t_vector step, t_vector pos)
{
	t_vector	draw;

	if (side == 1 || side == 2)
		sd->wall_dist = (sd->map_pos[0] - pos[0]
					+ (1 - step[0]) / 2) / sd->ray_dir[0];
	else if (side == 3 || side == 4)
		sd->wall_dist = (sd->map_pos[1] - pos[1]
					+ (1 - step[1]) / 2) / sd->ray_dir[1];
	if ((sd->line_height = (int)(H / sd->wall_dist)) <= 0)
		sd->line_height = 1;
	if ((draw[0] = -sd->line_height / 2 + H / 2) < 0)
		draw[0] = 0;
	if ((draw[1] = sd->line_height / 2 + H / 2) >= H)
		draw[1] = H - 1;
	return (draw);
}

t_surf		*ft_define_surf(t_surf *surf, int id, int surf_nbr)
{
	int		i;

	i = -1;
	while (++i < surf_nbr)
	{
		if (surf && surf[i].id == id)
			return (&surf[i]);
	}
	return (NULL);
}

void		ft_draw_wall_pillar(t_sd *sd, t_vector xy, int side)
{
	t_surf		*surf;
	int			i;
	double		k;
	t_color		color;

	i = -1;
	k = 1;
	color = sd->color;
	if (sd->wall_id == 42)
		surf = &sd->exit_surf;
	else
		surf = ft_define_surf(sd->surf, sd->wall_id, sd->surf_nbr);
	if (sd->wall_dist > 1)
		k = (double)1 / sd->wall_dist;
	while (xy[1] <= sd->draw[1])
	{
		if (surf != NULL || (surf == NULL && sd->side_text == 1))
			color = ft_apply_wall_text(sd, xy[1], surf, side);
		ft_putpixel(xy[0], xy[1], sd->screen, MULT_C(color, k));
		xy[1]++;
	}
}

void		ft_draw_pillar(t_sd *sd, int side, t_vector step, int x)
{
	t_vector	xy;
	t_vector	floor_wall;
	t_color		color;
	int			n;

	n = sd->l_nbr;
	sd->draw = ft_define_draw_extr(sd, side, step, sd->levels[n].pos);
	xy = (t_vector){x, sd->draw[0]};
	if (side == 1 || side == 2)
		sd->wall_x = sd->levels[n].pos[1] + sd->ray_dir[1] * sd->wall_dist;
	else
		sd->wall_x = sd->levels[n].pos[0] + sd->ray_dir[0] * sd->wall_dist;
	sd->wall_x -= floor(sd->wall_x);
	ft_draw_wall_pillar(sd, xy, side);
	if (sd->draw[1] < 0)
		sd->draw[1] = H;
	xy[1] = sd->draw[1];
	floor_wall = ft_define_floor_wall_coord(side, sd, sd->wall_x);
	while (++xy[1] <= H)
	{
		color = ft_apply_text(sd, xy[1], &sd->levels[n].floor_surf, floor_wall);
		ft_putpixel(xy[0], xy[1], sd->screen, color);
		color = ft_apply_text(sd, xy[1], &sd->ceiling_surf, floor_wall);
		ft_putpixel(xy[0], H - xy[1], sd->screen, MULT_C(color, 0.5));
	}
}
