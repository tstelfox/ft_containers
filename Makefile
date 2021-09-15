# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/14 16:41:04 by tmullan       #+#    #+#                  #
#    Updated: 2021/09/15 18:02:32 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = container
CXX = clang++
SRC = vector_main.cpp
OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Isrc/vector -Isrc/map

vector map:
	$(CXX) src/$@_main.cpp $(FLAGS) $(INCLUDES) -o $(NAME)

# $(OBJ_DIR)/%.o: %.cpp
# 	@mkdir -p $(@D)
# 	@echo "Compiling object files"
# 	$(CXX) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean al

