#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 999999

#include <stdio.h>

char	*copy_line(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
		i++;
	dest = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
//	ft_putendl(dest);
	return (dest);
}

int		trim_until(char *str, int delimeter)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != delimeter && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
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
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*arr;
	int			ret;

	(void)line;
	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (!arr)
	{
		arr = (char*)malloc(ft_strlen(buf + 1));
		ft_strcpy(arr, buf);
	}
	*line = copy_line(*line, arr);
	if (trim_until(arr, '\n') == 0)
		return (0);
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
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
