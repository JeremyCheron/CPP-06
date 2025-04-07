# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheron <jcheron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 09:55:13 by jcheron           #+#    #+#              #
#    Updated: 2025/04/03 08:07:50 by jcheron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -Iincludes -std=c++98 -g
SRC_DIR = src
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/ScalarConverter.cpp $(SRC_DIR)/printers.cpp \
		$(SRC_DIR)/wich.cpp
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/ScalarConverter.o $(OBJ_DIR)/printers.o \
		$(OBJ_DIR)/wich.o

NAME = ex00

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@mkdir -p $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
