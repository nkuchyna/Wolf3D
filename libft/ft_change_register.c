/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_register.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:34:03 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 17:37:09 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_change_to_upper_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

static void		ft_change_to_standart_str(char *str)
{
	int		i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	write(1, &str[i], 1);
	i++;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void			ft_change_register(char *str, int flag)
{
	int		i;

	i = 0;
	if (!str || !flag)
		return ;
	if (flag == 1)
		ft_change_to_upper_str(str);
	else if (flag == 2)
		ft_change_to_standart_str(str);
	else
		ft_putstr("Please, enter the second parameter 1 or 2.\n 1 - \
changes the strings' letters in upperrcase,\n 2 - modify string to the \
standart view.\n");
}
