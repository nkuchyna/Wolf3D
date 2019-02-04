/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:47:25 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/11 12:47:40 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_define_exect_side(int *side, t_vector step)
{
	if (*side == 0 && step[0] == 1)
		*side = 1;
	else if (*side == 0 && step[0] == -1)
		*side = 2;
	else if (*side == 1 && step[1] == 1)
		*side = 3;
	else if (*side == 1 && step[1] == -1)
		*side = 4;
}

static int		hit(t_sd *sd, t_vector s_dist, t_vector d_dist, t_vector step)
{
	int		hit;
	int		side;

	hit = 0;
	side = -1;
	while (hit == 0)
	{
		if (s_dist[0] < s_dist[1])
		{
			s_dist[0] += d_dist[0];
			sd->map_pos[0] += step[0];
			side = 0;
		}
		else
		{
			s_dist[1] += d_dist[1];
			sd->map_pos[1] += step[1];
			side = 1;
		}
		if ((sd->wall_id = ft_check_map(sd->map_pos, sd->levels[sd->l_nbr].map,
			sd->levels[sd->l_nbr].w, sd->levels[sd->l_nbr].h)) > 0)
			hit = 1;
	}
	ft_define_exect_side(&side, step);
	return (side);
}

static t_vector	ft_init_raycasting(t_sd *sd, t_vector plane, int x, int n)
{
	t_vector	d_dist;
	double		cam_x;

	sd->map_pos[0] = (int)sd->levels[n].pos[0];
	sd->map_pos[1] = (int)sd->levels[n].pos[1];
	cam_x = 2 * (double)x / WIDTH - 1;
	sd->ray_dir = sd->dir + MULT(plane, cam_x);
	d_dist[0] = (double)fabs(1 / sd->ray_dir[0]);
	d_dist[1] = (double)fabs(1 / sd->ray_dir[1]);
	return (d_dist);
}

static t_vector	ft_define_step_sdist(t_sd *sd, t_vector d_dist, t_vector pos)
{
	t_vector	step;

	if (sd->ray_dir[0] < 0)
	{
		step[0] = -1;
		sd->side_dist[0] = (pos[0] - sd->map_pos[0]) * d_dist[0];
	}
	else
	{
		step[0] = 1;
		sd->side_dist[0] = (sd->map_pos[0] + 1 - pos[0]) * d_dist[0];
	}
	if (sd->ray_dir[1] < 0)
	{
		step[1] = -1;
		sd->side_dist[1] = (pos[1] - sd->map_pos[1]) * d_dist[1];
	}
	else
	{
		step[1] = 1;
		sd->side_dist[1] = (sd->map_pos[1] + 1 - pos[1]) * d_dist[1];
	}
	return (step);
}

void			*ft_raycasting(t_sd *sd)
{
	t_vector	d_dist;
	t_vector	step;
	int			x;
	int			side;
	int			n;

	x = 0;
	n = sd->l_nbr;
	while (x < WIDTH)
	{
		side = 0;
		d_dist = ft_init_raycasting(sd, sd->plane, x, n);
		step = ft_define_step_sdist(sd, d_dist, sd->levels[n].pos);
		side = hit(sd, sd->side_dist, d_dist, step);
		if (side > 0)
			ft_draw_pillar(sd, side, step, x);
		x++;
	}
	ft_draw_torch(sd->torch, sd);
	return (NULL);
}
