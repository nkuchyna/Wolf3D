/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:03:20 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/04 20:31:28 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_str_empty(void)
{
	char		*str;

	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	return (str);
}

static void		ft_begin_end(char const *s, int *begin, int *end)
{
	int			i;

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		(*begin)++;
		i++;
	}
	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		(*end)++;
		i--;
	}
}

char			*ft_strtrim(char const *s)
{
	int			begin;
	int			end;
	int			i;
	int			k;
	char		*str;

	begin = 0;
	end = 0;
	i = 0;
	k = 0;
	if (s == NULL || ft_strlen(s) == 0)
		return ((char*)s);
	ft_begin_end(s, &begin, &end);
	if (begin == (int)ft_strlen(s))
		return (ft_str_empty());
	else
		str = ft_strnew(ft_strlen(s) - begin - end);
	if (str == NULL)
		return (NULL);
	i = begin;
	while (i < ((int)ft_strlen(s) - end))
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
