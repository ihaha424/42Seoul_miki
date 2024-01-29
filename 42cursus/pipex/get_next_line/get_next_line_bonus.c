/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:32:30 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/25 19:05:20 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_line(char *buff)
{
	int	size;
	int	index;

	index = 0;
	size = ft_strlen_gnl(buff);
	while (index < size)
	{
		if (buff[index] == '\n')
			return (index + 1);
		index++;
	}
	return (-1);
}

static char	*last(char **str)
{
	char	*line;

	if (!*str)
		return (NULL);
	line = ft_strdup_gnl(*str);
	if (!line || ft_strlen_gnl(line) == 0)
	{
		free(*str);
		free(line);
		*str = NULL;
		return (NULL);
	}
	free(*str);
	*str = NULL;
	return (line);
}

static char	*check(char **str)
{
	int		offset;
	int		len;
	char	*return_value;

	if (!*str)
		return (0);
	len = ft_strlen_gnl(*str);
	offset = find_line(*str);
	if (offset < 0)
		offset = len;
	return_value = (char *)malloc(sizeof(char) * offset + 1);
	if (!return_value)
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	ft_strlcpy_gnl(return_value, *str, offset + 1);
	ft_strlcpy_gnl(*str, *str + offset, len - offset + 1);
	return (return_value);
}

static char	*add_string(char *str, char *buff)
{
	char	*value;

	value = str;
	str = ft_strjoin_gnl(value, buff);
	free(value);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			eof;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (find_line(str[fd]) > 0)
			return (check(&str[fd]));
		eof = read(fd, buff, BUFFER_SIZE);
		if (eof == -1)
		{
			free(str[fd]);
			str[fd] = NULL;
			return (NULL);
		}
		if (eof == 0)
			return (last(&str[fd]));
		buff[eof] = '\0';
		str[fd] = add_string(str[fd], buff);
		if (!str[fd])
			return (NULL);
	}
}
