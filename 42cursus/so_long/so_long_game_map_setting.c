/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_map_setting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:49:06 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/24 20:56:04 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_map_oneline(char *buf, t_game *game)
{
	char	*temp;
	char	*temp2;
	int		width;

	temp = ft_strtrim(buf, "\n");
	if (!temp)
		error(0);
	width = ft_strlen(temp);
	if (game->width != width)
	{
		ft_putstr_fd("It's not a rectangular.\n", 2);
		error(3);
	}
	temp2 = game->map;
	game->map = ft_strjoin(game->map, temp);
	free(temp2);
	free(temp);
	if (!game->map)
		error(0);
}

void	map_read(int fd, t_game *game)
{
	char	*buf;
	int		height;

	height = 1;
	buf = get_next_line(fd);
	game->map = ft_strtrim(buf, "\n");
	if (!game->map)
		error(0);
	game->width = ft_strlen(game->map);
	while (buf)
	{
		free(buf);
		buf = get_next_line(fd);
		if (!buf)
			break ;
		height++;
		get_map_oneline(buf, game);
	}
	game->height = height;
	close(fd);
}

static int	check_char(char map)
{
	if (map != '1' && map != '0' && map != 'E' && map != 'P' && map != 'C')
		return (0);
	return (1);
}

static void	counting_char(char c, t_game *game)
{
	if (c == 'E')
		game->g_exit++;
	if (c == 'P')
		game->g_start++;
	if (c == 'C')
		game->g_coin++;
	if (c == 'T')
		game->g_monster++;
}

void	check(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (!check_char(game->map[i]))
			error(3);
		if (i >= 0 && i < game->width)
			convert_border(game, i);
		else if (i >= game->width * (game->height - 1) && \
		i < game->width * game->height)
			convert_border(game, i);
		else if (i % game->width == 0 || i % game->width == game->width - 1)
			convert_border(game, i);
		if (game->map[i] == '0' && (game->random % 10) == 0)
			game->map[i] = 'T';
		counting_char(game->map[i], game);
		game->random = random_int(game);
	}
}
