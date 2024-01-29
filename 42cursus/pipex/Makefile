# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:49:28 by dongmiki          #+#    #+#              #
#    Updated: 2023/06/22 16:18:36 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
BONUS = bonus
LIB = pipex.a
LIB_B = pipex_bonus.a
LIBFT = Libft
SRCS = pipex.c\
	pipex_utils.c\
	pipex_arg_check.c\
	
OBJS = $(SRCS:.c=.o)

SRCS_B = pipex_bonus.c\
	pipex_utils.c\
	pipex_arg_check.c\
	get_next_line/get_next_line_bonus.c\
	get_next_line/get_next_line_utils_bonus.c\

OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
    OBJ = $(OBJS_B)
else
    OBJ = $(OBJS)
endif
	
all: $(NAME)

bonus:
	@make WITH_BONUS:=1 all
	
$(NAME) : $(OBJ)
	make -C $(LIBFT)
	cp Libft/libft.a $(LIB)
	ar rcs $(LIB) $?
	$(CC) $(CFLAGS) $(LIB) -o $@
	rm -f $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus