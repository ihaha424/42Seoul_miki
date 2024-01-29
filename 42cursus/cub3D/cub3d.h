/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongrol <jeongrol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:22:19 by jeongrol          #+#    #+#             */
/*   Updated: 2023/10/15 15:41:54 by jeongrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"

# define BUFFER_SIZE	42
# define FAIL 			0
# define SUCCESS		1

# define WIDTH		1280
# define HEIGHT		960
# define MINWIDTH	330
# define MINHEIGHT	210
# define MINTILE	30

//Key fuction
# define KEY_ESC			53
# define KEY_EVENT_PRESS	2
# define KEY_EVENT_EXIT		17
# define A	0
# define S	1
# define D	2
# define W	13
# define K	40
# define ONE 18

//MOUSE
# define LEFT_CLICK		1
# define RIGHT_CLICK	2

//Math
# define PI	3.14159265359

typedef struct s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		line_size;
	int		width;
	int		height;
	int		endian;
}	t_img;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_info
{
	void		*mlx;
	void		*win;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			f_color;
	int			c[3];
	int			c_color;
	int			info_cnt;
	char		pos_dir;
	int			dx[8];
	int			dy[8];
	int			row;
	int			col;
	char		**map;
	t_vec2		dir_vec;
	t_vec2		pos;
	t_vec2		camera;
	t_img		mini;
	t_img		screen;
	t_img		map_tex[4];
	t_img		door[13];
	t_img		sprite;
	t_img		rider;
	t_img		boom;
	int			ani;
	int			ani_time;
	int			mouse;
	int			door_num;
}	t_info;

typedef struct t_screen
{
	int		map[2];
	int		step[2];
	int		draw[2];
	int		line_height;
	int		side;
	int		what_hit;
	int		tex_x;
	t_vec2	ray;
	t_vec2	side_dis;
	t_vec2	delta_dis;
	double	ray_distance;
}	t_screen;


// utils
// utils_libft.c
int		ft_strlen(const char *str);
char	*ft_strdup(const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_itoa(char *str);
char	*ft_strjoin(char *buff, char *tmp, int tmp_len);
// utils_cub3d.c
int		ft_two_strlen(char **str);
void	ft_two_free(char **str);
void	ft_error(char *str);
char	**ft_two_strdup(char **str);
int		check_empty_line(char *line);
// utils_split.c
char	**ft_split(char const *str, char c);
// get_next_line
char	*get_next_line(int fd);
void	free_all(char *a, char *b);
int		ft_linelen(const char *s);
char	*delete_new_line(char *line);
char	*replace_tab(char *line);
// parsing
// parsing_cub3d.c
void	parsing_cub3d(int ac, char **av, t_info *info);
// parsing_set_info.c
void	input_info(char **av, t_info *info);
// parsing_validate_info_basic.c
void	validate_info_element(t_info *info);
void	validate_info_map_char(t_info *info, int x, int y, char c);
// parsing_validate_info_detail.c
void	validate_info_map_wall(t_info *info, int x, int y);
void	validate_info_map_emptyline(t_info *info, int x, int y, int flag);
// excute_hook
int		key_press(int keycode, t_info *g);
int		exit_button(void);
// excute_loop_hook
int		draw_loop(t_info *game);
void	where_tex_x(t_screen *s, t_info *game);
void	where_hit_wall(t_screen *s, t_info *game);
void	draw_screen(t_info *game, int time);
// excute_minimap
void	draw_minimap(t_info *game);
// excute door
void	draw_door(t_info *game, int x, t_screen *screen, int time);
void	rotate_door(t_info *game);
void	door_control(t_info *game);
void	change_door(t_info *game);
int		find_door(t_info *game);
// excute_utils
void	setting_mlx(t_info *game, int i);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	rotate(int keycode, t_info *g);
double	ft_abs(double num);
// excute mouse event
void	mouse_event(t_info *game);
int		mouse_event2(int keycode, int x, int y, t_info *game);

#endif