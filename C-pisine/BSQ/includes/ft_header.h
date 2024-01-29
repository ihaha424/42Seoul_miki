/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:19:14 by seokhcho          #+#    #+#             */
/*   Updated: 2022/09/15 11:12:47 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		x_size;
	int		y_size;
	char	empty_ch;
	char	obstacle_ch;
	char	full_ch;
}	t_map_info;

typedef struct s_square
{
	int	start_x;
	int	start_y;
	int	size;
}	t_square;

// ft_main.c
void	handle_stdin(void);
void	handle_input(char *str);

// ft_get_file_contents.c
int		check_file_exist(char *file_name);
int		get_one_line(char *file_name);
char	**split_one_line(int ch_count, char *file_name, int *size);

// ft_split.c
char	**ft_split(char *str, char *charset, int *size);
int		def_charset(char s1, char *s2);
int		count_strings(char *str, char*charset);
int		ft_strlen_sep(char *str, char*charset);
char	*ft_word(char *str, char *charset);

// ft_handle_splited_str.c
int		check_error(char **splited_str, int size);
int		check_first_row(char *square_info_str, t_map_info *map_info);
int		check_contents(char **splited_str, t_map_info *map_info, int size);
int		check_one_line(char *one_line, t_map_info *map_info);

// ft_atoi.c
int		ft_atoi(char *str, int cnt);
int		ft_strlen(char *str);

// ft_algorithm.c
void	square(int **map, t_map_info *info);
void	change_map(t_square big, t_map_info *info);
int		find_position(int **map, t_map_info *info);
int		convert_map2(t_map_info *info, int **map);
int		convert_map(t_map_info *info);

#endif