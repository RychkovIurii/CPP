# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irychkov <irychkov@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 15:54:30 by irychkov          #+#    #+#              #
#    Updated: 2025/04/07 15:54:52 by irychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clap_trap
SRCS = main.cpp ClapTrap.cpp
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
