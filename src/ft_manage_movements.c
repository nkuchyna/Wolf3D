/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:50:36 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/09/16 17:51:05 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_play_sound_steps(t_sd *sd)
{
	if (sd->l_nbr == 0)
		Mix_PlayChannel(-1, sd->sound1, 0);
	else
		Mix_PlayChannel(-1, sd->sound2, 0);
}

static char	*ft_change_text_str(int i)
{
	char	*samples_nbr;
	char	*tmp;

	samples_nbr = ft_itoa(i);
	tmp = ft_strjoin(ft_strdup("LEVEL "), samples_nbr);
	return (tmp);
}

static int	ft_mng_frwrd_movm(t_sd *sd, t_level *level, int *ret_x, int *ret_y)
{
	t_vector	tmp_pos;
	int			ret;

	ret = 0;
	tmp_pos = level->pos;
	if ((*ret_x = ft_check_map((t_vector){level->pos[0] + sd->dir[0] * 0.6,
			level->pos[1]}, level->map, level->w, level->h)) == 0)
	{
		level->pos[0] += sd->dir[0] * 0.04;
		ret = 1;
	}
	if ((*ret_y = ft_check_map((t_vector){level->pos[0], level->pos[1] +
		sd->dir[1] * 0.6}, level->map, level->w, level->h)) == 0)
	{
		level->pos[1] += sd->dir[1] * 0.04;
		ret = 1;
	}
	if (!(*ret_x) && !(*ret_y) && ft_check_map(level->pos + MULT(sd->dir, 0.2),
	level->map, level->w, level->h) != 0)
		level->pos = tmp_pos;
	return (ret);
}

static int	ft_manage_next_level(t_sd *sd, int ret_x, int ret_y)
{
	char	*tmp_text;

	tmp_text = NULL;
	if (ret_x == EXIT || ret_y == EXIT)
	{
		sd->l_nbr++;
		if (sd->l_nbr < 3)
			Mix_PlayChannel(1, sd->level_sound, 0);
		SDL_FreeSurface(sd->l_text);
		tmp_text = ft_change_text_str(sd->l_nbr + 1);
		sd->l_text = TTF_RenderText_Solid(sd->font, tmp_text, sd->text_col);
		ft_strdel(&tmp_text);
		return (1);
	}
	return (0);
}

void		ft_manage_movements(t_sd *sd, t_level *level)
{
	int		ret_x;
	int		ret_y;

	if (sd->rotate == 1)
		ft_rotate_camera(sd, SHIFT);
	else if (sd->rotate == 2)
		ft_rotate_camera(sd, 2 * M_PI - SHIFT);
	if (sd->go == 1)
	{
		if (ft_mng_frwrd_movm(sd, level, &ret_x, &ret_y) == 1)
			ft_play_sound_steps(sd);
		if (ft_manage_next_level(sd, ret_x, ret_y))
			return ;
	}
	else if (sd->go == 2 && ft_check_map(level->pos - MULT(sd->dir, 0.6),
		level->map, level->w, level->h) == 0)
	{
		level->pos -= MULT(sd->dir, 0.04);
		ft_play_sound_steps(sd);
	}
}
