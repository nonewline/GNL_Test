#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 42

#include <stdio.h>

void	trim_until(char *str, int delimeter)
{
	int i; //Copy from
	int j; //Copy to

	j = 0;
	i = 0;
	while (str[i] != delimeter)
		i++;
	i++;
	while (str[j])
	{
		if (str[i])
			str[j] = str[i];
		else
			str[j] = '\0';
		i++;
		j++;
	}
	str[j] = '\0';
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*arr;
	int			ret;

	(void)line;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (!arr)
	{
		arr = (char*)malloc(ft_strlen(buf + 1));
		ft_strcpy(arr, buf);
	}
	trim_until(arr, '\n');
	ft_putendl(arr);
	return (1);
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
//	while (get_next_line(fd, &line) == 1)
//	{
//		ft_putendl(line);
//		free(line);
//	}
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	if (argc == 2)
		close(fd);
}
