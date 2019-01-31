#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define N_LOCATION (char *)ft_memchr(current->buf, '\n', (size_t)current->len)
#define N_LOCATION_S (char *)ft_memchr(current->buf, '\n', (size_t)current->olen)

int	ft_init(t_lst **lst, int fd)
{
	if (!(*lst = ft_memalloc(sizeof(t_lst))))
		return (-1);
	(*lst)->fd = fd;
	(*lst)->isn = 1;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static t_lst	*lst;
	t_lst			*current;
	char			*tmp;
	ssize_t 		len;

	tmp = ft_memalloc(0);
	len = 0;
	if (!line || fd < 0 || (read(fd, tmp, 0) == -1))
		return (-1);
	ft_memdel((void	**)&tmp);
	if (!lst)
	{
		if (ft_init(&lst, fd))
			return (-1);
	}
	current = lst;
	if (fd != current->fd)
	{
		while(current->next && fd != current->fd)
			current = current->next;
		if (fd != current->fd)
		{
			if (!(current->next = ft_memalloc(sizeof(t_lst))))
				return (-1);
		current = current->next;
		current->fd = fd;
		current->isn = 1;
		}
	}
	if (!(current->null))
		*line = ft_strnew(0);
	while (1)
	{
		if (!(current->len))
			current->len = read(fd, current->buf, BUFF_SIZE);
		if (!(current->len))
		{
			if (!current->isn)
			{
				(*line)[len] = '\0';
				current->isn = 1;
				current->null = 1;
				return (1);
			}
			return (0);
		}
		if (N_LOCATION)
		{
			*line = (char *)ft_memfjoin((void **)line, current->buf, (size_t)len, ((size_t)(N_LOCATION - current->buf)) + 1);
			current->isn = 1;
			len += (N_LOCATION - current->buf);
			(*line)[len] = '\0';
			current->olen = current->len;
			current->len = current->len - (N_LOCATION - current->buf);
			tmp = ft_memalloc((size_t)current->len);
			ft_memcpy(tmp, N_LOCATION_S, (size_t)current->len);
			ft_bzero(current->buf, (size_t)current->olen);
			ft_memcpy(current->buf, tmp, (size_t)current->len);
			free(tmp);
			if (current->len > 1)
			{
				current->olen = current->len;
				current->len = current->len - 1;
				tmp = ft_memalloc((size_t)current->len);
				ft_memcpy(tmp, current->buf + 1, (size_t)current->len);
				ft_bzero(current->buf, (size_t)current->olen);
				ft_memcpy(current->buf, tmp, (size_t)current->len);
				free(tmp);
			}
			else
			{
				*(current->buf) = '\0';
				current->len = 0;
			}
			(*line)[len] = '\0';
			return (1);
		}
		else
		{
			*line = ft_memfjoin((void **) line, current->buf, (size_t) len, (size_t) current->len);
			len += current->len;
			current->len = 0;
			*(current->buf) = '\0';
			current->olen = 0;
			current->isn = 0;
		}
	}
}
