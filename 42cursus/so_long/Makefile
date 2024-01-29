# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 17:36:01 by dongmiki          #+#    #+#              #
#    Updated: 2023/07/08 13:53:47 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLX = -L ./mlx -lmlx -framework OpenGL -framework AppKit
LIBFT = Libft
NAME = so_long
SRCS = so_long.c \
		so_long_error.c\
		so_long_event.c\
		so_long_game_img_setting.c\
		so_long_game_map_setting.c\
		so_long_game_map_setting2.c\
		so_long_game.c\
		so_long_move.c\
		get_next_line/get_next_line_bonus.c\
		get_next_line/get_next_line_utils_bonus.c\

OBJS = $(SRCS:.c=.o)
HEAD = so_long.h

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	make -C $(LIBFT)
	make -C mlx/
	$(CC) $(CFLAGS) Libft/libft.a $(MLX) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I./ -o $@

clean :
	rm -f $(OBJS)
	rm -f *.a
	make clean -C $(LIBFT)
	make clean -C mlx

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean bonus re