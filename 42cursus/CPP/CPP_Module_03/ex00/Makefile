# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:58:31 by dongmiki          #+#    #+#              #
#    Updated: 2024/01/09 20:30:32 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = ClapTrap
SRCS = 	main.cpp\
		ClapTrap.cpp	
OBJS = $(SRCS:.cpp=.o)
%.o:%.cpp
	$(CC) $(CFLAG) -c $< -o $@
HEAD = 	ClapTrap.hpp

all: $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
