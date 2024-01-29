# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:58:31 by dongmiki          #+#    #+#              #
#    Updated: 2024/01/04 16:18:17 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLANG = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRCS = 	PhoneBook.cpp\
		Contact.cpp
OBJS = $(SRCS:.cpp=.o)
HEAD = 	Contact.hpp\
		PhoneBook.hpp
		

all: $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re