/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:22:18 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/05 18:08:41 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		ft_full(char **str, char **line)
{
	char	*tmp;
	char	*index;

	tmp = *str;
	if ((index = ft_strchr(*str, '\n')))
		*index = '\0';
	*line = ft_strdup(*str);
	*str = NULL;
	if (index && ft_strlen(index + 1))
		*str = ft_strdup(index + 1);
	ft_strdel(&tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*str[4864];
	int			n;

	if (!line || fd < 0 || read(fd, buff, 0))
		return (-1);
	while ((n = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[n] = '\0';
		if (!str[fd])
			str[fd] = ft_strnew(0);
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		ft_strdel(&tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (!n && !str[fd])
		return (0);
	return (ft_full(&str[fd], line));
}
