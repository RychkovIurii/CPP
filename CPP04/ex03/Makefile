# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 12:29:50 by irychkov          #+#    #+#              #
#    Updated: 2025/04/18 16:41:23 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interfaces
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp ICharacter.cpp IMateriaSource.cpp
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
