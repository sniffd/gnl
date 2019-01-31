#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <libc.h>

int main(int argc, char **argv)
{
	int fd;
	int i;
	char *line;

	fd = 0;
	i = 1;
	line = NULL;
	if (argc >= 2)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			i++;
			while (get_next_line(fd, &line))
			{
				ft_putendl(line);
				free(line);
			}
		}
	}
}
