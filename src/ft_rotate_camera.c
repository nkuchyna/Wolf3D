/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 17:55:33 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/12 17:55:48 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vector	ft_rotate_vector(t_vector dir, double ang)
{
	double	tmp_x;

	tmp_x = dir[0];
	dir[0] = dir[0] * cos(ang) - dir[1] * sin(ang);
	dir[1] = tmp_x * sin(ang) + dir[1] * cos(ang);
	return (dir);
}

void		ft_rotate_camera(t_sd *sd, double ang)
{
	sd->dir = ft_rotate_vector(sd->dir, ang);
	sd->plane = ft_rotate_vector(sd->plane, ang);
}
