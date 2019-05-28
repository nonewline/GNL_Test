/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:36:42 by zmahomed          #+#    #+#             */
/*   Updated: 2019/05/28 13:46:13 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 999999
# define GET_NEXT_LINE_H

char	*copy_line(char *dest, char *src);
int		trim_until(char *str, int delimeter);
int		get_next_line(const int fd, char **line);
char	*ft_strcpy(char *dest, char *src);
int		ft_strlen(char *str);

#endif
