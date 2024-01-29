/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_door_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:10:12 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/13 18:55:20 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	change_door(t_info *game)
{
	int	x;
	int	y;

	x = (int)game->pos.x;
	y = (int)game->pos.y;
	if (game->map[x - 1][y] == 'D')
		game->map[x - 1][y] = '#';
	else if (game->map[x + 1][y] == 'D')
		game->map[x + 1][y] = '#';
	else if (game->map[x][y - 1] == 'D')
		game->map[x][y - 1] = '#';
	else if (game->map[x][y + 1] == 'D')
		game->map[x][y + 1] = '#';
	else if (game->map[x - 1][y] == '#')
		game->map[x - 1][y] = 'D';
	else if (game->map[x + 1][y] == '#')
		game->map[x + 1][y] = 'D';
	else if (game->map[x][y - 1] == '#')
		game->map[x][y - 1] = 'D';
	else if (game->map[x][y + 1] == '#')
		game->map[x][y + 1] = 'D';
}

int	find_door(t_info *game)
{
	int	x;
	int	y;

	x = (int)game->pos.x;
	y = (int)game->pos.y;
	if (game->map[x - 1][y] == 'D' || game->map[x + 1][y] == 'D' \
	|| game->map[x][y - 1] == 'D' || game->map[x][y + 1] == 'D')
		return (1);
	else if (game->map[x - 1][y] == '#' || game->map[x + 1][y] == '#' \
	|| game->map[x][y - 1] == '#' || game->map[x][y + 1] == '#')
		return (2);
	return (0);
}

void	door_control(t_info *game)
{
	int	flag;

	flag = find_door(game);
	if (flag > 0 && game->door_num < 12)
		game->door_num++;
}

void	rotate_door(t_info *game)
{
	if (game->door_num > 0)
	{
		if ((game->ani % 5) == 0 && game->door_num < 12)
			game->door_num++;
		if (game->door_num == 12)
		{
			game->door_num = 0;
			change_door(game);
		}
	}
}
