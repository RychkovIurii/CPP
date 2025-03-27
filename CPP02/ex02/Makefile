# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 09:18:04 by irychkov          #+#    #+#              #
#    Updated: 2025/03/27 15:51:49 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed_point_numbers_operators
SRCS = main.cpp Fixed.cpp
OBJ = $(SRCS:.cpp=.o)
COMPILER = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17

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
