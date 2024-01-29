/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_splited_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:06:13 by seokhcho          #+#    #+#             */
/*   Updated: 2022/09/15 12:32:52 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int	check_error(char **splited_str, int size)
{
	t_map_info	map_info;
	int			i;

	if (check_first_row(splited_str[0], &map_info) != 0)
	{
		if (check_contents(splited_str, &map_info, size) != 0)
		{
			map_info.map = &splited_str[1];
			convert_map(&map_info);
			i = -1;
			while (++i < size)
				free(splited_str[i]);
			free(splited_str);
			return (1);
		}
	}
	i = -1;
	while (++i < size)
		free(splited_str[i]);
	free(splited_str);
	return (0);
}

int	check_first_row(char *square_info_str, t_map_info *map_info)
{
	int	length_of_str;
	int	idx_started_from_last;

	length_of_str = ft_strlen(square_info_str);
	if (length_of_str < 4)
		return (0);
	idx_started_from_last = (length_of_str - 1);
	map_info -> full_ch = square_info_str[idx_started_from_last--];
	map_info -> obstacle_ch = square_info_str[idx_started_from_last--];
	map_info -> empty_ch = square_info_str[idx_started_from_last--];
	map_info -> y_size = ft_atoi(square_info_str, idx_started_from_last + 1);
	return (1);
}

int	check_contents(char **splited_str, t_map_info *map_info, int size)
{
	int	line;
	int	count;

	line = 1;
	map_info->x_size = check_one_line(splited_str[line], map_info);
	while (line < size)
	{
		count = check_one_line(splited_str[line], map_info);
		if (count == 0)
			return (0);
		else
		{
			if (map_info->x_size != count)
				return (0);
		}
		line++;
	}
	if (line - 1 != map_info->y_size)
		return (0);
	return (1);
}

int	check_one_line(char *one_line, t_map_info *map_info)
{
	int		col;
	char	ch;

	col = 0;
	while (one_line[col] != '\0')
	{
		ch = one_line[col];
		if ((ch != map_info->empty_ch) && (ch != map_info->obstacle_ch))
		{
			return (0);
		}
		col++;
	}
	return (col);
}
