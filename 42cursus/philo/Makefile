# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 17:36:01 by dongmiki          #+#    #+#              #
#    Updated: 2023/08/22 16:07:08 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SRCS = philo.c\
		philo_utils.c\
		philo_setting.c\
		philo_error.c\
		philo_action.c\
		philo_action2.c\
		Lib/ft_atoi.c\
		Lib/ft_putstr_fd.c\
		Lib/ft_strlen.c\

OBJS = $(SRCS:.c=.o)
HEAD = philo.h

all : $(NAME)


$(NAME) : $(OBJS) $(HEAD)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I./ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus re