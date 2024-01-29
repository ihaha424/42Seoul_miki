/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:35:51 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/25 02:56:53 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line_bonus.h"
# include "./Libft/libft.h"

# define KEY_PRESS	2
# define KEY_EXIT	17
# define ESC		53
# define A			0
# define S			1
# define D			2
# define W			13
# define K			40

typedef struct s_img
{
	void	*empty;
	void	*exit;
	void	*coin;
	void	*player;
	void	*wall;
	void	*skill[6];
	void	*trash;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		g_coin;
	int		g_exit;
	int		g_point;
	int		g_start;
	int		g_walk;
	int		g_monster;
	int		g_kill;
	int		random;
	int		animation;
	int		g_skill;
	int		skill[9];
	int		time;
	int		press;
	char	*map;
	t_img	img;
}	t_game;

int		main(int ac, char *av[]);
int		keypress_event(int key, t_game *game);
int		click_redcross(t_game *game);
int		random_int(t_game *game);
int		animation(t_game *game);
int		press_correct(t_game *game, int key);
void	error(int error_case);
void	setting_img(t_game *game);
void	map_read(int fd, t_game *game);
void	check(t_game *game);
void	convert_border(t_game *game, int i);
void	skill_action(t_game *game, int i);
void	monster(t_game *game);
void	move_exit(t_game *game, int move, int i);
void	skill_effect(t_game *game, int i);
void	finish_skill(t_game *game);
void	animate(t_game *g, int w, int h);
t_game	*check_game(char *map);

#endif