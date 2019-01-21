#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <libc.h>
#include "project.h"
int	main()
{
//	int	fd;
//	char	*str = malloc(1024);
//	ft_bzero(str, 1024);
//	fd = open("/Users/fdaryn-h/Desktop/test", O_RDWR);
//	get_next_line(fd, &str);
//	printf("%s", str);
//	char	str[4];
//	int		fd;
//	ssize_t	i;
//	i = 0;
//	fd = open("/Users/fdaryn-h/Desktop/test", O_RDONLY);
//	i = read(fd, str, 10);
//	char	*src = "qwe";
//	char	dst[] = "456";
//
//	printf("%zu\n", strlcat(dst, src, 2));
//	printf("%s\n", dst);
//	printf("%s\n", strncat(dst, "123", -1));
//	printf("%s\n", ft_strncat(dst, "123", -1));
//	char 	*str = ft_strsplit("123*45*6*78*9*", '*');
//	printf("%s", str);
//	int fd = open("/Users/fdaryn-h/Desktop/test", O_RDONLY);
//	char *line;
//	while (get_next_line(fd, &line))
//		printf("%s\n", line);
//	return (0);

//		char		*line;
//		int			fd;
//		int			ret;
//		int			count_lines;
//		char		*filename;
//		int			errors;
//
//		filename = "/Users/fdaryn-h/Desktop/gnl1_1.txt";
//		fd = open(filename, O_RDONLY);
//		if (fd > 2)
//		{
//			count_lines = 0;
//			errors = 0;
//			line = NULL;
//			while ((ret = get_next_line(fd, &line)) > 0)
//			{
//				if (count_lines == 0 && strcmp(line, "1234567") != 0)
//					errors++;
//				count_lines++;
//				if (count_lines > 50)
//					break;
//			}
//			close(fd);
//			if (count_lines != 1)
//				printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
//			if (errors > 0)
//				printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
//			if (count_lines == 1 && errors == 0)
//				printf("OK\n");
//		}
//		else
//			printf("An error occured while opening file %s\n", filename);
//		return (0);
//	char		*line;
//	int			fd;
//	int			ret;
//	int			count_lines;
//	char		*filename;
//	int			errors;
//
//	filename = "/Users/fdaryn-h/Desktop/gnl_to_free_or_not_to_free.txt";
//	fd = open(filename, O_RDONLY);
//	if (fd > 2)
//	{
//		count_lines = 0;
//		errors = 0;
//		line = NULL;
//		while ((ret = get_next_line(fd, &line)) > 0)
//		{
//			if (count_lines == 0 && strcmp(line, "This is the first line") != 0)
//				errors++;
//			if (count_lines == 1 && strcmp(line, "This is the second one") != 0)
//				errors++;
//			if (count_lines == 2 && strcmp(line, "This is the third") != 0)
//				errors++;
//			if (count_lines == 3 && strcmp(line, "This is the last") != 0)
//				errors++;
//			count_lines++;
//			free(line);
//			if (count_lines > 50)
//				break ;
//		}
//		close(fd);
//		if (count_lines != 4)
//			printf("-> must have returned '1' four times instead of %d time(s)\n", count_lines);
//		if (errors > 0)
//			printf("-> must have read \"This is the first line\", \"This is the second one\", \"This is the third\", \"This is the last\".\n");
//		if (count_lines == 4 && errors == 0)
//			printf("OK");
//	}
//	else
//		printf("An error occured while opening file %s\n", filename);
//	char 	*line;
//	int		out;
//	int		p[2];
//	int		fd;
//
//	out = dup(1);
//	pipe(p);
//
//	fd = 1;
//	dup2(p[1], fd);
//	write(fd, "mnopqrstuvwxyzab", 16);
//	close(p[1]);
//	dup2(out, fd);
//	get_next_line(p[0], &line);
//	char 	*line;
//	int		out;
//	int		p[2];
//	int		fd;
//	int		gnl_ret;
//
//	out = dup(1);
//	pipe(p);
//
//	fd = 1;
//	dup2(p[1], fd);
//	write(fd, "abc\n\n", 5);
//	close(p[1]);
//	dup2(out, fd);
//
//	/* Read abc and new line */
//	gnl_ret = get_next_line(p[0], &line);
//	mt_assert_base(gnl_ret == 1, NULL, 0);
//	mt_assert_base(strcmp(line, "abc") == 0, NULL, 0);
//
//	/* Read new line */
//	gnl_ret = get_next_line(p[0], &line);
//	mt_assert_base(gnl_ret == 1, NULL, 0);
//	mt_assert_base(line == NULL || *line == '\0', NULL, 0);
//
//	/* Read again, but meet EOF */
//	gnl_ret = get_next_line(p[0], &line);
//	mt_assert_base(gnl_ret == 0, NULL, 0);
//	mt_assert_base(line == NULL || *line == '\0', NULL, 0);
//
//	/* Let's do it once again */
//	gnl_ret = get_next_line(p[0], &line);
//	mt_assert_base(gnl_ret == 0, NULL, 0);
//	mt_assert_base(line == NULL || *line == '\0', NULL, 0);
//	char	*line;
//	int fd = open("/Users/fdaryn-h/Downloads/tst", O_RDONLY);
//	while (get_next_line(fd, &line))
//		printf("%s\n", line);
	int res;
	char *line;
	int i = 0;

	while((res = get_next_line(0, &line)) > 0)
	{
		if (i++ > 10)
			break;
		printf("%d|%s\n", res, line);
		if (res == 1)
			free(line);
	}
	printf("res:%d\n", res);
	return (0);
}
