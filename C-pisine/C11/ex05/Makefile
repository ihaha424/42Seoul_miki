# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 14:37:47 by dongmiki          #+#    #+#              #
#    Updated: 2022/09/15 13:10:15 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = do-op
SRCS = srcs/operation.c srcs/do_op.c
CC = gcc
CFAGS = -Wall -Wextra -Werror

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFAGS) $(SRCS) -o $(TARGET)

clean :
	rm -rf $(TARGET)
fclean : clean

re : fclean all

.PHONY : all clean fclean do-op re
