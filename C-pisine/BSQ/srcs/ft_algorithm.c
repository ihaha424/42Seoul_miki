/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokhcho <seokhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:25:59 by seokhcho          #+#    #+#             */
/*   Updated: 2022/09/15 03:13:46 by seokhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

void	square(int **map, t_map_info *info)
{
	int	x;
	int	y;
	int	min;

	x = 1;
	y = 1;
	while (y < info->y_size)
	{
		x = 1;
		while (x < info->x_size)
		{
			if (map[y][x] == 1)
			{
				min = map[y - 1][x - 1];
				if (min > map[y - 1][x])
					min = map[y - 1][x];
				if (min > map[y][x - 1])
					min = map[y][x - 1];
				map[y][x] = min + 1;
			}
			x++;
		}
		y++;
	}
}

void	change_map(t_square big, t_map_info *info)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (++y < big.size)
	{
		x = -1;
		while (++x < big.size)
			info->map[big.start_y - y][big.start_x - x] = info->full_ch;
	}
	y = -1;
	while (++y < info->y_size)
	{
		x = -1;
		while (++x < info->x_size)
		{
			c = info->map[y][x];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

int	find_position(int **map, t_map_info *info)
{
	t_square	big;
	int			x;
	int			y;

	big.size = 0;
	square(map, info);
	y = -1;
	while (++y < info -> y_size)
	{
		x = -1;
		while (++x < info -> x_size)
		{
			if (map[y][x] > big.size)
			{
				big.start_x = x;
				big.start_y = y;
				big.size = map[y][x];
			}
		}
	}
	change_map(big, info);
	return (1);
}

int	convert_map2(t_map_info *info, int **map)
{
	int	y;

	if (!(find_position(map, info)))
		return (0);
	y = -1;
	while (++y < info->y_size)
		free(map[y]);
	free(map);
	return (1);
}

int	convert_map(t_map_info *info)
{
	int	x;
	int	y;
	int	**map;

	map = (int **)malloc(sizeof(int *) * info->y_size);
	if (!map)
		return (0);
	y = -1;
	while (++y < info->y_size)
	{
		map[y] = (int *)malloc(sizeof(int) * info->x_size);
		if (!map[y])
			return (0);
		x = -1;
		while (++x < info->x_size)
		{
			if (info->map[y][x] == info->empty_ch)
				map[y][x] = 1;
			else
				map[y][x] = 0;
		}
	}
	if ((convert_map2(info, map)) == 0)
		return (0);
	return (1);
}
