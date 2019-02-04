/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:46:36 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/03 18:52:53 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*del_list;
	t_list		*next_list;

	del_list = *alst;
	if (!alst || !(*alst) || !del)
		return ;
	while (del_list)
	{
		next_list = del_list->next;
		del(del_list->content, del_list->content_size);
		free(del_list);
		del_list = next_list;
	}
	(*alst) = NULL;
}
