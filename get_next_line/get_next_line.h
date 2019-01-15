#define BUFF_SIZE 3
#include "../libft/libft.h" //fixme
//typedef struct	s_ls
//{
//	char			*buf;
//	struct s_ls		*next;
//	ssize_t			len;
//}				t_ls;

typedef struct	s_lst
{
	int				fd;
	char			buf[BUFF_SIZE];
//	t_ls			*sbuf;
	ssize_t 		len;
//	ssize_t			wnum;
	int				end;
	struct s_lst	*next;
}				t_lst;
int	get_next_line(const int fd, char **line);
