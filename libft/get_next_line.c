/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 14:30:35 by mlokhors       #+#    #+#                */
/*   Updated: 2019/12/02 22:14:35 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"
#include <limits.h>

static void		ft_strreplace(char **s, char *n)
{
	free(*s);
	*s = n;
}

static	int		followup(int fd, char **line, char **cache)
{
	unsigned int i;

	i = 0;
	if (ft_strchr(cache[fd], '\n') != NULL)
	{
		while (cache[fd][i] && cache[fd][i] != '\n')
			i++;
		*line = ft_strsub(cache[fd], 0, i);
		ft_strreplace(&cache[fd], ft_strdup(cache[fd] + i + 1));
		return (1);
	}
	if (cache[fd][0] == '\0')
	{
		*line = NULL;
		ft_strdel(&cache[fd]);
		return (0);
	}
	else
	{
		*line = ft_strdup(cache[fd]);
		cache[fd] = ft_strnew(0);
		return (1);
	}
}

int				ft_get_next_line(const int fd, char **line)
{
	int				bytes_read;
	static char		*cache[10240];
	char			*buff;

	buff = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, 0) < 0 || !line)
		return (-1);
	bytes_read = 1;
	if (!cache[fd])
		cache[fd] = ft_strnew(0);
	while (bytes_read > 0 && ft_strchr(cache[fd], '\n') == NULL)
	{
		ft_bzero(buff, BUFF_SIZE + 1);
		bytes_read = read(fd, buff, BUFF_SIZE);
		ft_strreplace(&cache[fd], ft_strjoin(cache[fd], buff));
	}
	free(buff);
	return (followup(fd, line, cache));
}
