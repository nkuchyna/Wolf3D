/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:18:03 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/04 19:25:25 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
			s++;
		if (*s == c || (*s == '\0' && *(s - 1) != c))
			nb++;
	}
	return (nb);
}

static char		*ft_mall_word(const char *s, char c)
{
	int			size;
	char		*word;
	int			i;

	size = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	word = ft_strnew(size + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**ft_clean_array(char **ptr_words, int i)
{
	while (i >= 0)
		free(ptr_words[i--]);
	free(ptr_words);
	return (NULL);
}

static char		**ft_fill_array(char **ptr_words, const char *s, char c)
{
	int			i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			if (!(ptr_words[i] = ft_mall_word(s, c)))
				return (ft_clean_array(ptr_words, i));
			i++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ptr_words;
	int			nb;

	if (!s || !c)
		return (NULL);
	nb = ft_count_words(s, c);
	ptr_words = (char**)malloc(sizeof(char*) * (nb + 1));
	if (ptr_words == NULL)
		return (NULL);
	return (ft_fill_array(ptr_words, s, c));
}
