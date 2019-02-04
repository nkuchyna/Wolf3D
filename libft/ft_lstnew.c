/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:21:59 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 13:47:16 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*ft_lstnew_check(size_t content_size)
{
	t_list		*new_l;

	content_size = 0;
	new_l = (t_list*)malloc(sizeof(t_list));
	if (new_l == NULL)
		return (NULL);
	if (new_l)
	{
		new_l->content = NULL;
		new_l->content_size = 0;
		new_l->next = NULL;
	}
	return (new_l);
}

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_l;
	void		*copy_content;
	int			flag;

	flag = 0;
	if (content == NULL || content_size == 0)
	{
		new_l = ft_lstnew_check(content_size);
		return (new_l);
	}
	copy_content = ft_memalloc(content_size);
	if (copy_content == NULL)
		return (NULL);
	ft_memcpy(copy_content, content, content_size);
	new_l = (t_list*)malloc(sizeof(t_list));
	if (new_l == NULL)
		return (NULL);
	if (new_l)
	{
		new_l->content = copy_content;
		new_l->content_size = content_size;
		new_l->next = NULL;
	}
	return (new_l);
}
