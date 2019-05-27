#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 4200

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char arr[BUFF_SIZE + 1];
	static int 	read_line;
	int			cur_line;
	int			ret;
	int			i;

	(void)line;
	cur_line = 0;
	i = 0;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (buf[i] != '\0')
		ft_strcpy(arr, buf);
	while (arr[i])
	{
		if (arr[i] == '\n')
			cur_line++;
		else if (cur_line == read_line)
			ft_putchar(arr[i]);
		else if (cur_line > read_line)
			break;
		i++;
	}
	read_line++;
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	get_next_line(fd, &line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putchar('\n');
	if (argc == 2)
		close(fd);
}
