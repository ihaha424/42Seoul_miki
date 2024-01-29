# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 10:50:25 by dongmiki          #+#    #+#              #
#    Updated: 2022/09/15 20:08:43 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
CC  = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes

all : ${NAME}

${NAME} : ${OBJS}
	ar -cr ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -I ${HEADER} -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : fclean clean all re
