/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_img_setting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:41:53 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/25 03:02:02 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game *g, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.empty, w * 64, h * 64);
	if (g->map[h * g->width + w] == '1' || g->map[h * g->width + w] == '2')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall, \
		w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.coin, \
		w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player, \
		w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'O')
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.exit, \
		w * 64, h * 64);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player, \
		w * 64, h * 64);
	}
	else if (g->map[h * g->width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.exit, \
		w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'T')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.trash, \
		w * 64, h * 64);
}

static void	put_string(t_game *game)
{
	char	*temp;

	mlx_string_put(game->mlx, game->mlx_win, 0, \
	(game->height) * 64 + 32, 0xFFFFFF, "Move: wasd    Skill: K");
	mlx_string_put(game->mlx, game->mlx_win, 0, \
	(game->height + 1) * 64 + 32, 0xFFFFFF, "Step: ");
	temp = ft_itoa(game->g_walk);
	if (!temp)
		error(0);
	mlx_string_put(game->mlx, game->mlx_win, 64, \
	(game->height + 1) * 64 + 32, 0xFFFFFF, temp);
	free(temp);
	mlx_string_put(game->mlx, game->mlx_win, 128, \
	(game->height + 1) * 64 + 32, 0xFFFFFF, "Kill: ");
	temp = ft_itoa(game->g_kill);
	if (!temp)
		error(0);
	mlx_string_put(game->mlx, game->mlx_win, 192, \
	(game->height + 1) * 64 + 32, 0xFFFFFF, temp);
	free(temp);
}

void	setting_img(t_game *game)
{
	int		current_h;
	int		current_w;

	mlx_clear_window(game->mlx, game->mlx_win);
	current_h = 0;
	while (current_h < game->height)
	{
		current_w = 0;
		while (current_w < game->width)
		{
			put_img(game, current_w, current_h);
			current_w++;
		}
		current_h++;
	}
	put_string(game);
}

int	random_int(t_game *game)
{
	game->random = (game->random * 1103515245 + 12345) & RAND_MAX;
	return (game->random);
}

void	animate(t_game *g, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], (w - 1) * 64, (h - 1) * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], w * 64, (h - 1) * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], (w + 1) * 64, (h - 1) * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], (w - 1) * 64, h * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], (w + 1) * 64, h * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], (w - 1) * 64, (h + 1) * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], w * 64, (h + 1) * 64);
	mlx_put_image_to_window(g->mlx, g->mlx_win, \
				g->img.skill[g->animation], (w + 1) * 64, (h + 1) * 64);
}
