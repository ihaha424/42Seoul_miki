/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_contents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:15:41 by seokhcho          #+#    #+#             */
/*   Updated: 2022/09/15 11:13:02 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int	check_file_exist(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		return (0);
	close(fd);
	return (1);
}

int	get_one_line(char *file_name)
{
	int		fd;
	int		ch_count;
	char	buf[1];

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		return (0);
	ch_count = 0;
	while (read(fd, buf, 1))
		ch_count++;
	close(fd);
	return (ch_count);
}

char	**split_one_line(int ch_count, char *file_name, int *size)
{
	char	*one_line_str;
	char	**splited_str;
	char	buf[1];
	int		fd;
	int		idx;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		return (0);
	one_line_str = (char *)malloc(sizeof(char) * (ch_count + 1));
	if (one_line_str == 0)
		return (NULL);
	one_line_str[ch_count] = '\0';
	idx = 0;
	while (read(fd, buf, 1))
	{
		one_line_str[idx] = buf[0];
		idx++;
	}
	splited_str = ft_split(one_line_str, "\n", size);
	close(fd);
	return (splited_str);
}
