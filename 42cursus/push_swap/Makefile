# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:49:28 by dongmiki          #+#    #+#              #
#    Updated: 2023/02/25 20:23:15 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIB = push_swap.a
LIBFT = Libft
CHECKER = checker
SRCS = push_swap.c\
	ft_greedy.c\
	ft_push.c\
	ft_reverce_rotate.c\
	ft_rotate.c\
	ft_sort.c\
	ft_swap.c\
	ft_utils.c\
	make_stack.c\
	get_next_line/get_next_line_bonus.c\
	get_next_line/get_next_line_utils_bonus.c
	
OBJS = $(SRCS:.c=.o)

SRCS_B = ft_checker.c\
	ft_greedy.c\
	ft_push.c\
	ft_reverce_rotate.c\
	ft_rotate.c\
	ft_sort.c\
	ft_swap.c\
	ft_utils.c\
	make_stack.c\
	get_next_line/get_next_line_bonus.c\
	get_next_line/get_next_line_utils_bonus.c

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

bonus : $(CHECKER)

$(CHECKER) : $(OBJS_B)
	make -C $(LIBFT)
	cp Libft/libft.a $(LIB)
	ar rcs $(LIB) $?
	$(CC) $(CFLAGS) $(LIB) -o $@
	rm -f $(LIB)

$(NAME) : $(OBJS)
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
	rm -f $(CHECKER)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus