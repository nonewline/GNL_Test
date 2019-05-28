/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:38:37 by zmahomed          #+#    #+#             */
/*   Updated: 2019/05/28 13:53:34 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
	dest[i] = '\0';
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
