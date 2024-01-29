/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:03:15 by dongmiki          #+#    #+#             */
/*   Updated: 2023/07/05 14:32:16 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	skill(t_game *game)
{
	unsigned int	i;

	game->g_skill = 1;
	game->animation = 0;
	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P' || game->map[i] == 'O')
			break ;
		i++;
	}
	skill_action(game, i);
}

static void	clear_game(t_game *game, int flag)
{
	game->g_walk += 1;
	if (flag)
		ft_putstr_fd("\nSuccess!\n", 1);
	else
		ft_putstr_fd("\nYou were caught by Jiwoo. \n\
You are a slave from now on!\n", 1);
	ft_putstr_fd("Your step count is: ", 1);
	ft_putnbr_fd(game->g_walk, 1);
	ft_putstr_fd("\nYour kill Jiwoo count is: ", 1);
	ft_putnbr_fd(game->g_kill, 1);
	write(1, "\n", 1);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(EXIT_SUCCESS);
}

static void	press_key(t_game *game, int move)
{
	unsigned int	i;

	i = -1;
	while (++i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P' || game->map[i] == 'O')
			break ;
	}
	if (game->map[i + move] == 'C')
		game->g_point += 1;
	if (game->map[i + move] == 'E' && game->g_coin == game->g_point)
		clear_game(game, 1);
	else if (game->map[i + move] == 'T')
		clear_game(game, 0);
	else if (game->map[i + move] != '1' && game->map[i + move] != '2')
	{
		game->g_walk += 1;
		ft_putnbr_fd(game->g_walk, 1);
		write(1, "\n", 1);
		if (game->map[i + move] == 'E' || game->map[i] == 'O')
			return (move_exit(game, move, i));
		game->map[i] = '0';
		game->map[i + move] = 'P';
		setting_img(game);
	}
}

int	click_redcross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	keypress_event(int key, t_game *game)
{
	int	i;

	if (game->press)
		return (0);
	game->press = 1;
	if (key == ESC)
		click_redcross(game);
	else if (key == K)
		skill(game);
	else
	{
		i = press_correct(game, key);
		if (i != 0)
		{			
			if (game->g_skill == 1)
				finish_skill(game);
			press_key(game, i);
			monster(game);
		}
	}
	game->press = 0;
	return (0);
}
