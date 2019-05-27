/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 07:28:15 by zmahomed          #+#    #+#             */
/*   Updated: 2019/05/27 13:19:34 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#define BUF_SIZE 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int 	ft_read(char *buf)
{
	int i = 0;
	static int line;
	int cur_line = 0;

	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			cur_line++;
		else if (cur_line == line)
			ft_putchar(buf[i]);
		i++;
	}
	line++;
	return (0);
}

int		get_next_line(int fd)
{
	static char	buf[BUF_SIZE + 1];
	int		ret;

	if (fd == 3)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		ft_read(buf);
		return (1);
	}
	close(fd);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		ft_putstr("File name missing.\n");
	if (ac > 2)
		ft_putstr("Too many arguments.\n");
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd);
		ft_putchar('\n');
		get_next_line(fd);
		ft_putchar('\n');
	}
	return (0);
}
