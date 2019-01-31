#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define BUFF_SIZE 10
#include "../libft/libft.h" //fixme

typedef struct	s_lst
{
	int				fd;
	char			buf[BUFF_SIZE];
	ssize_t 		len;
	ssize_t 		olen;
	int 			isn;
	int 			null;
	struct s_lst	*next;
}				t_lst;
int	get_next_line(const int fd, char **line);

#endif
