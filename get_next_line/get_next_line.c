#include "get_next_line.h"
#include <unistd.h>

//t_ls	*ft_buf(ssize_t len, char *buf)//TODO сократить строки
//{
//	ssize_t	i;
//	t_ls	*lst;
//	t_ls	*head;
//
//	if (!(lst = (t_ls *)ft_memalloc(sizeof(t_ls))))
//		return (0);
//	head = lst;
//	if (!ft_memchr(buf, '\n', (size_t)len))
//	{
//		if (!(lst->buf = ft_memalloc(sizeof(char) * len)))
//			return (0);
//		lst->len = len;
//		lst->next = 0;
//		ft_memcpy(lst->buf, buf, (size_t)len);
//		return (head);
//	}
//	while (1)
//	{
//		i = (char *)ft_memchr(buf, '\n', (size_t)len) - buf;
//		lst->buf = ft_memalloc(sizeof(char) * i);
//		lst->len = i;
//		ft_memcpy(lst->buf, buf, (size_t)i);
//		if (ft_memchr(buf, '\n', (size_t)len) == ft_memrchr(buf, '\n', (size_t)len))
//		{
//			if (!(lst->next = ft_memalloc(sizeof(char) * len - (((char *) ft_memchr(buf, '\n', (size_t)len) - buf) + 1))))
//				return 0;
//			ft_memcpy(lst->next, (ft_memchr(buf, '\n', (size_t)len) + 1), len - (((char *) ft_memchr(buf, '\n', (size_t)len) - buf) + 1));
//			lst->next->next = 0;
//			return (head);
//		}
//		lst = lst->next;
//		len = len - i;
//		buf = ft_memchr(buf, '\n', (size_t)len--) + 1;
//	}
//}

int	ft_init(t_lst **lst, int fd)
{
	if (!(*lst = ft_memalloc(sizeof(t_lst))))
		return (-1);
	(*lst)->fd = fd;
	(*lst)->len = read(fd, (*lst)->buf, BUFF_SIZE);
	(*lst)->stop = (*lst)->buf;
//	(*lst)->sbuf = ft_buf((*lst)->len, (*lst)->buf);
	if ((*lst)->len < BUFF_SIZE)
		(*lst)->end = 1;
	return (0);
}

int	ft_is_n(const char *buf, int n)
{
	int	i;
	i = 0;

	while (i < n)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)//TODO переписать ЕБУЧИЙ ГНЛ
{
	static t_lst	*lst;
	t_lst			*current;
	char			*str;
	ssize_t 		len;

	str = ft_memalloc(0);
	len = 0;
	if (!line || fd < 0 || (read(fd, str, 0) == -1))
		return (-1);
	ft_memdel((void	**)&str);
	if (!lst)
	{
		if (ft_init(&lst, fd))
			return (-1);
	}
	current = lst;
	*line = ft_strnew(0);
	if (fd != current->fd)
	{
		while(current->next && fd != current->fd)
			current = current->next;
		if (!(current->next = ft_memalloc(sizeof(t_lst))))
			return (-1);
		current = current->next;
		current->len = read(fd, current->buf, BUFF_SIZE);
		current->stop = current->buf;
		current->end = current->len == BUFF_SIZE ? 0 : 1;
		current->fd = fd;
	}
	while (1)
	{
		if (!(current->len - (current->stop - current->buf)))
		{
			current->len = read(fd, current->buf, BUFF_SIZE);
			current->stop = current->buf;
			current->end = current->len == BUFF_SIZE ? 0 : 1;
		}
		if (ft_is_n(current->stop, (int)(current->len - (current->stop - current->buf))))
		{
			*line = ft_memjoin(*line, current->stop, (size_t)len, (size_t)(current->len - (current->stop - current->buf)));
			current->stop = ft_is_n(current->stop, (int)(current->len - (current->stop - current->buf)));//fixme
		}
		*line = ft_memjoin(*line, current->buf, (size_t)len, (size_t)current->len);
		len += current->len;
		return (1);
//		else if (ft_is_n(current->buf) == BUFF_SIZE)
//		{
//			if (current->buf)
//				*line = ft_strjoin(*line, current->buf);
//			(current->wnum)++;
//			current->end = read(fd, current->buf, BUFF_SIZE) == BUFF_SIZE ? 0 : 1;
//			if (!(current->len))
//				return (0);
//		}
//		else
//		{
////			current->len = ft_is_n(current->buf);
//			str = ft_strsub(current->buf, 0, current->len);
//			*line = ft_strjoin(*line, str);
//			(current->wnum)++;
//			return (1);
//		}
	}
}
