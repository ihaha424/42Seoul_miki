# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 11:59:43 by dongmiki          #+#    #+#              #
#    Updated: 2022/09/15 12:07:49 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/ft_main.c srcs/ft_split.c srcs/ft_handle_splited_str.c srcs/ft_get_file_contents.c srcs/ft_atoi.c srcs/ft_algorithm.c

OBJS = ${SRCS:.c=.o}
TRASH = file_name

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = includes

all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} -g

%.o : %.c
	${CC} ${CFLAGS} -c $< -I ${HEADER} -o $@

clean : 
		rm -f ${OBJS}
		rm -f ${TRASH}

fclean : clean
		rm -f ${NAME}

re	:	fclean all

.PHONY : fclean clean do-op all re
