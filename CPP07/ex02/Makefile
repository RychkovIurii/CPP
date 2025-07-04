# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 11:33:16 by irychkov          #+#    #+#              #
#    Updated: 2025/07/04 13:56:51 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array
SRCS = main.cpp
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
