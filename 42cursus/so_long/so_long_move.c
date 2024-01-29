/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:58:31 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/25 03:02:34 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_exit(t_game *game, int move, int i)
{
	if (game->map[i + move] == 'E')
	{
		game->map[i] = '0';
		game->map[i + move] = 'O';
	}
	else
	{
		game->map[i] = 'E';
		game->map[i + move] = 'P';
	}
	setting_img(game);
}

void	skill_effect(t_game *g, int i)
{
	int	h;
	int	w;
	int	pos;

	h = -1;
	pos = 0;
	while (++h < g->height)
	{
		w = -1;
		while (++w < g->width)
		{
			if (pos == i)
				return (animate(g, w, h));
			pos++;
		}
	}
}

int	animation(t_game *game)
{
	unsigned int	i;

	game->time++;
	if (game->g_skill == 1 && ((game->time % 3000) == 0))
	{
		i = 0;
		while (i < ft_strlen(game->map))
		{
			if (game->map[i] == 'P' || game->map[i] == 'O')
				break ;
			i++;
		}
		game->animation++;
		game->time = 0;
		setting_img(game);
		skill_effect(game, i);
		if (game->animation == 5)
			game->animation = 3;
		if (game->animation == 5 || game->animation == 4)
			game->time = 2000;
	}
	return (1);
}

void	finish_skill(t_game *game)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P' || game->map[i] == 'O')
			break ;
		i++;
	}
	game->map[i - game->width - 1] = game->skill[0];
	game->map[i - game->width] = game->skill[1];
	game->map[i - game->width + 1] = game->skill[2];
	game->map[i - 1] = game->skill[3];
	game->map[i + 1] = game->skill[5];
	game->map[i + game->width - 1] = game->skill[6];
	game->map[i + game->width] = game->skill[7];
	game->map[i + game->width + 1] = game->skill[8];
	game->g_skill = 0;
}

int	press_correct(t_game *game, int key)
{
	if (key == A)
		return (-1);
	else if (key == S)
		return (game->width);
	else if (key == D)
		return (1);
	else if (key == W)
		return (-game->width);
	return (0);
}
