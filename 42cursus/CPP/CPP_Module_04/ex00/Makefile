# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:58:31 by dongmiki          #+#    #+#              #
#    Updated: 2024/01/15 14:56:44 by dongmiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = Animal
SRCS = 	main.cpp\
		Animal.cpp\
		Cat.cpp\
		Dog.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)
%.o:%.cpp
	$(CC) $(CFLAG) -c $< -o $@
HEAD = 	Animal.hpp\
		Cat.hpp\
		Dog.hpp\
		WrongAnimal.hpp\
		WrongCat.hpp

all: $(NAME)

$(NAME) : $(OBJS) $(HEAD)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re