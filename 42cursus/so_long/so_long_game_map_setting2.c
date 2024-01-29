/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_map_setting2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:04:27 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/25 02:48:19 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	convert_border(t_game *game, int i)
{
	if (game->map[i] != '1')
		error(4);
	else
		game->map[i] = '2';
}

static void	skill_img(t_game *game, int position, int *skill, int num)
{
	skill[num] = game->map[position];
	if (skill[num] == '1')
		skill[num] = '0';
	if (skill[num] == 'T')
	{
		skill[num] = '0';
		game->g_monster--;
		game->g_kill++;
	}
	if (skill[num] != '2' && skill[num] != 'C' && skill[num] != 'E')
		game->map[position] = 'S';
}

void	skill_action(t_game *game, int i)
{
	setting_img(game);
	skill_img(game, i - game->width - 1, game->skill, 0);
	skill_img(game, i - game->width, game->skill, 1);
	skill_img(game, i - game->width + 1, game->skill, 2);
	skill_img(game, i - 1, game->skill, 3);
	skill_img(game, i + 1, game->skill, 5);
	skill_img(game, i + game->width - 1, game->skill, 6);
	skill_img(game, i + game->width, game->skill, 7);
	skill_img(game, i + game->width + 1, game->skill, 8);
	skill_effect(game, i);
	game->map[i - game->width - 1] = game->skill[0];
	game->map[i - game->width] = game->skill[1];
	game->map[i - game->width + 1] = game->skill[2];
	game->map[i - 1] = game->skill[3];
	game->map[i + 1] = game->skill[5];
	game->map[i + game->width - 1] = game->skill[6];
	game->map[i + game->width] = game->skill[7];
	game->map[i + game->width + 1] = game->skill[8];
}

static int	monster_move(t_game *game)
{
	int	move;

	game->random = random_int(game);
	move = game->random % 4;
	if (move == 0)
		return (-1);
	else if (move == 1)
		return (-game->width);
	else if (move == 2)
		return (1);
	else
		return (game->width);
}

void	monster(t_game *game)
{
	unsigned int	i;
	int				k;
	int				move;

	i = -1;
	k = -1;
	while (++k < game->g_monster)
	{
		while (++i < ft_strlen(game->map))
			if (game->map[i] == 'T')
				break ;
		move = monster_move(game);
		if (game->map[i + move] == '0')
		{
			game->map[i] = '0';
			game->map[i + move] = 'T';
		}
	}
}
