/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:00:19 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/08/17 15:02:39 by nkuchyna         ###   ########.fr       */
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

char			*ft_strjoin_n(char **s1, char **s2)
{
	size_t		i[2];
	char		*str;
	char		*temp1;
	char		*temp2;

	i[0] = 0;
	i[1] = 0;
	temp1 = *s1;
	temp2 = *s2;
	if (temp1 == NULL || temp2 == NULL)
		return (NULL);
	if (ft_strlen(temp1) == 0 && ft_strlen(temp2) == 0)
		return (ft_str_empty());
	str = ft_strnew(ft_strlen(temp1) + ft_strlen(temp2));
	if (str == NULL)
		return (NULL);
	while (temp1[i[1]] != '\0')
		str[i[0]++] = temp1[i[1]++];
	i[1] = 0;
	while (temp2[i[1]] != '\0')
		str[i[0]++] = temp2[i[1]++];
	str[i[0]] = '\0';
	ft_strdel(s1);
	ft_strdel(s2);
	return (str);
}
