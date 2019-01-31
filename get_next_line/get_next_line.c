/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:40:58 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/01/31 22:50:03 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define N_LOCATION (char *)ft_memchr((*list)->buf, '\n', (size_t)(*list)->len)

int		init_and_else(t_lst **lst, int fd, ssize_t *len, int f)
{
	if (!f)
	{
		if (!(*lst = ft_memalloc(sizeof(t_lst))))
			return (-1);
		(*lst)->fd = fd;
		(*lst)->isn = 1;
		return (0);
	}
	else
	{
		(*((*lst)->line)) = ft_memfjoin((void **)(*lst)->line, (*lst)->buf,
				(size_t)*len, (size_t)(*lst)->len);
		*len += (*lst)->len;
		(*lst)->len = 0;
		*((*lst)->buf) = '\0';
		(*lst)->olen = 0;
		(*lst)->isn = 0;
		return (0);
	}
}

void	changebuf(t_lst **list, ssize_t len, int f)
{
	char	*tmp;

	tmp = 0;
	(*list)->olen = (*list)->len;
	(*list)->len = len;
	tmp = ft_memalloc((size_t)(*list)->len);
	if (f)
		ft_memcpy(tmp, (*list)->buf + 1, (size_t)(*list)->len);
	else
		ft_memcpy(tmp, ((char *)ft_memchr((*list)->buf, '\n',
				(size_t)(*list)->olen)), (size_t)(*list)->len);
	ft_bzero((*list)->buf, (size_t)(*list)->olen);
	ft_memcpy((*list)->buf, tmp, (size_t)(*list)->len);
	free(tmp);
}

int		write_line(t_lst **list, char **line, ssize_t *len)
{
	if (N_LOCATION)
	{
		*line = (char *)ft_memfjoin((void **)line, (*list)->buf,
				(size_t)*len, ((size_t)(N_LOCATION - (*list)->buf)) + 1);
		(*list)->isn = 1;
		*len += (N_LOCATION - (*list)->buf);
		(*line)[*len] = '\0';
		changebuf(&(*list), ((*list)->len - (N_LOCATION - (*list)->buf)), 0);
		if ((*list)->len > 1)
			changebuf(&(*list), ((*list)->len - 1), 1);
		else
		{
			*((*list)->buf) = '\0';
			(*list)->len = 0;
		}
		(*line)[*len] = '\0';
		return (1);
	}
	else
	{
		(*list)->line = line;
		return (init_and_else(list, 0, len, 1));
	}
}

int		get_line(t_lst **list, int fd, char **line)
{
	ssize_t	len;

	len = 0;
	while (1)
	{
		if (!((*list)->len))
			(*list)->len = read(fd, (*list)->buf, BUFF_SIZE);
		if (!((*list)->len))
		{
			if (!(*list)->isn)
			{
				(*line)[len] = '\0';
				(*list)->isn = 1;
				(*list)->null = 1;
				return (1);
			}
			return (0);
		}
		if (write_line(list, line, &len))
			return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	t_lst			*current;
	char			*tmp;

	tmp = ft_memalloc(0);
	if (!line || fd < 0 || (read(fd, tmp, 0) == -1))
		return (-1);
	ft_memdel((void	**)&tmp);
	if (!lst && init_and_else(&lst, fd, 0, 0))
		return (-1);
	current = lst;
	while (current->next && fd != current->fd)
		current = current->next;
	if (fd != current->fd)
	{
		if (!(current->next = ft_memalloc(sizeof(t_lst))))
			return (-1);
		current = current->next;
		current->fd = fd;
		current->isn = 1;
	}
	if (!(current->null))
		*line = ft_strnew(0);
	return (get_line(&current, fd, line));
}
