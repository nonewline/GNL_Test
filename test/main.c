#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 99999

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char arr[BUFF_SIZE + 1];
	static int 	read_line;
	int			cur_line;
	int			ret;
	int			i;
	int			returnval;

	(void)line;
	cur_line = 0;
	i = 0;
	returnval = -1;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (buf[i] != '\0')
		ft_strcpy(arr, buf);
	line = (char**)malloc(BUFF_SIZE);
	while (arr[i])
	{
		if (arr[i] == '\n')
			cur_line++;
		else if (cur_line == read_line)
		{
			ft_putchar(arr[i]);
			*line++ = &arr[i];
		}
		else if (cur_line > read_line)
		{
			returnval = 1;
			break;
		}
		i++;
	}
	read_line++;
	return (returnval);
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
	while (get_next_line(fd, &line) >= 0)
	{
		ft_putchar('\n');
	}
	close(fd);
}
