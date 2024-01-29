/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 16:00:53 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/25 00:34:51 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 4] == '.')
		if (str[i - 3] == 'b')
			if (str[i - 2] == 'e')
				if (str[i - 1] == 'r')
					return ;
	error(1);
}

static t_img	img_init(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.empty = mlx_xpm_file_to_image(mlx, "./img/empty.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	img.exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &w, &h);
	img.coin = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &w, &h);
	img.skill[0] = mlx_xpm_file_to_image(mlx, "./img/skill1.xpm", &w, &h);
	img.skill[1] = mlx_xpm_file_to_image(mlx, "./img/skill1_2.xpm", &w, &h);
	img.skill[2] = mlx_xpm_file_to_image(mlx, "./img/skill2.xpm", &w, &h);
	img.skill[3] = mlx_xpm_file_to_image(mlx, "./img/skill3.xpm", &w, &h);
	img.skill[4] = mlx_xpm_file_to_image(mlx, "./img/skill4.xpm", &w, &h);
	img.skill[5] = mlx_xpm_file_to_image(mlx, "./img/skill5.xpm", &w, &h);
	img.trash = mlx_xpm_file_to_image(mlx, "./img/trash.xpm", &w, &h);
	return (img);
}

static void	map_error(t_game *game)
{
	check(game);
	if (game->g_coin < 1)
	{
		ft_putstr_fd("Not invaild Coin.\n", 2);
		error(3);
	}
	if (game->g_start != 1)
	{
		ft_putstr_fd("Not invaild Start position.\n", 2);
		error(3);
	}
	if (game->g_exit != 1)
	{
		ft_putstr_fd("Not invaild Exit.\n", 2);
		error(3);
	}
}

static void	game_init(t_game *game, int fd)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	game->g_coin = 0;
	game->g_point = 0;
	game->g_exit = 0;
	game->g_walk = 0;
	game->g_point = 0;
	game->g_start = 0;
	game->g_monster = 0;
	game->g_kill = 0;
	game->animation = 0;
	game->g_skill = 0;
	game->time = 0;
	game->press = 0;
	map_read(fd, game);
	map_error(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, \
					(game->height + 2) * 64, "so_long");
	setting_img(game);
}

t_game	*check_game(char *map)
{
	t_game	*game;
	int		fd_map;
	int		fd;
	char	buff[1];

	check_map_name(map);
	fd_map = open(map, O_RDONLY);
	if (fd_map < 0)
		error(2);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(0);
	fd = open("/dev/random", O_RDONLY);
	read(fd, buff, 1);
	close(fd);
	game->random = buff[0];
	game_init(game, fd_map);
	close(fd_map);
	return (game);
}
