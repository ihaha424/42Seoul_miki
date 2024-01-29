/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:32:30 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/30 21:48:47 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line(char *buff)
{
	int	size;
	int	index;

	index = 0;
	size = ft_strlen(buff);
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
	line = ft_strdup(*str);
	if (!line || ft_strlen(line) == 0)
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
	len = ft_strlen(*str);
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
	ft_strlcpy(return_value, *str, offset + 1);
	ft_strlcpy(*str, *str + offset, len - offset + 1);
	return (return_value);
}

static char	*add_string(char *str, char *buff)
{
	char	*value;

	value = str;
	str = ft_strjoin(value, buff);
	free(value);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (find_line(str) > 0)
			return (check(&str));
		eof = read(fd, buff, BUFFER_SIZE);
		if (eof == -1)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		if (eof == 0)
			return (last(&str));
		buff[eof] = '\0';
		str = add_string(str, buff);
		if (!str)
			return (NULL);
	}
}
