# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 12:29:50 by irychkov          #+#    #+#              #
#    Updated: 2025/04/15 14:04:21 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphism
SRCS = main.cpp Dog.cpp Cat.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp
OBJ = $(SRCS:.cpp=.o)
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++17

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
