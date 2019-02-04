/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:57:14 by nkuchyna          #+#    #+#             */
/*   Updated: 2018/05/13 14:59:21 by nkuchyna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_readlist		*ft_search_read_list(t_readlist **list, int fd)
{
	t_readlist		*node;

	node = *list;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	}
	if (!node)
	{
		if (!(node = (t_readlist*)malloc(sizeof(t_readlist) * 1)))
			return (NULL);
		node->str = NULL;
		node->fd = fd;
		node->get_end = 0;
		node->next = *list;
		*list = node;
	}
	return (node);
}

char			*ft_remalloc(char *str, int *size, int *read_position)
{
	char		*new_str;
	int			i;
	char		*temp;

	temp = str;
	i = 0;
	*size += BUFF_SIZE;
	if (!(new_str = ft_strnew((size_t)*size)))
	{
		free(str);
		return (NULL);
	}
	while (temp[i] != '\0')
	{
		new_str[i] = temp[i];
		i++;
	}
	new_str[i] = '\0';
	*read_position = i;
	free(str);
	return (new_str);
}

int				ft_search_str(t_readlist *lst, char **line, int count)
{
	char		*new_line;

	if (lst->str != NULL && !(ft_strchr(lst->str, '\n'))
		&& lst->get_end == 1 && *lst->str != '\0')
	{
		count = ft_strchr(lst->str, '\0') - lst->str;
		*line = ft_strsub(lst->str, 0, count);
		new_line = ft_strsub(lst->str, count, (int)ft_strlen(lst->str) - count);
		free(lst->str);
		lst->str = new_line;
		return (1);
	}
	else if (lst->str != NULL && ft_strchr(lst->str, '\n'))
	{
		count = ft_strchr(lst->str, '\n') - lst->str + 1;
		*line = ft_strsub(lst->str, 0, count - 1);
		new_line = ft_strsub(lst->str, count, (int)ft_strlen(lst->str) - count);
		free(lst->str);
		lst->str = new_line;
		if (count == 0 && lst->str[1] == '\0' && lst->get_end == 1)
			return (0);
		return (1);
	}
	return (0);
}

int				ft_read(char *buf, int fd, char **line, t_readlist *list)
{
	int			ret;
	int			size;
	int			read_position;

	read_position = 0;
	size = BUFF_SIZE;
	while ((ret = read(fd, &buf[read_position], BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buf[ret + read_position] = '\0';
		if (!(ft_strchr(buf, '\n')))
		{
			if (!(buf = ft_remalloc(buf, &size, &read_position)))
				return (-1);
		}
		else
			break ;
	}
	((int)ft_strlen(buf) < size) ? (list->get_end = 1) : (list->get_end *= 0);
	if (list->str != NULL && ft_strlen(buf) != 0)
		buf = ft_strjoin(list->str, buf);
	(ft_strlen(buf)) ? (list->str = buf) : (free(buf));
	return (ft_search_str(list, &(*line), 0));
}

int				get_next_line(const int fd, char **line)
{
	int					count;
	static t_readlist	*read_list;
	t_readlist			*list;
	char				*buf;
	int					end;

	count = 0;
	if (!(list = ft_search_read_list(&read_list, fd)) || fd == -1
		|| BUFF_SIZE < 1)
		return (-1);
	if ((list->str != NULL && ft_strchr(list->str, '\n'))
		|| (list->str != NULL && list->get_end == 1
		&& *list->str != '\0'))
		return (ft_search_str(list, &(*line), 0));
	else
	{
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		end = ft_read(buf, fd, &(*line), list);
		if (end == -1)
			free(buf);
		return (end);
	}
}
