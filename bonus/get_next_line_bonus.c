/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:37:10 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/28 09:31:14 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static int	check_nl(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*join(char *line, char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line != NULL && line[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + BUFFER_SIZE + 1));
	i = 0;
	while (line != NULL && line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
	{
		str[i] = buf[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}

static int	cut(char *line, char **buf)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	*buf = malloc(sizeof(char) * (i + 2));
	j = 0;
	while (j <= i)
	{
		(*buf)[j] = line[j];
		j++;
	}
	(*buf)[j] = '\0';
	if (check_nl(line) == 0 || line[j] == '\0')
		return (1);
	i = 0;
	while (line[j] != '\0')
	{
		line[i] = line[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			read_bytes;
	static char	*line[1024];

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buf[read_bytes] = '\0';
		line[fd] = join(line[fd], buf);
		if (check_nl(line[fd]) == 1)
			break ;
	}
	free(buf);
	buf = NULL;
	if (line[fd] != NULL)
		read_bytes = cut(line[fd], &buf);
	if (read_bytes == 1)
	{
		free(line[fd]);
		line[fd] = NULL;
	}
	return (buf);
}
