/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:49:31 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/04/02 16:11:31 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*modif_lst;
	t_list		*new_lst;
	t_list		*header;

	if (!lst || !f)
		return (NULL);
	modif_lst = f(lst);
	new_lst = ft_lstnew(modif_lst->content, modif_lst->content_size);
	if (new_lst == NULL)
		return (NULL);
	header = new_lst;
	header->next = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		modif_lst = f(lst);
		new_lst->next = ft_lstnew(modif_lst->content, modif_lst->content_size);
		if (new_lst->next == NULL)
			return (NULL);
		new_lst = new_lst->next;
	}
	new_lst->next = NULL;
	return (header);
}
