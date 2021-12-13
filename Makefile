# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/14 16:41:04 by tmullan       #+#    #+#                  #
#    Updated: 2021/12/13 20:30:42 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = container
CXX = clang++
SRC = vector_main.cpp
OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Isrc/vector -Isrc/map -Isrc/iterators -Isrc/utils

ifdef SEGS
	FLAGS += -fsanitize=address -g
endif


map vector:
	@echo Compiling $@
	@$(CXX) src/$@_main.cpp $(FLAGS) $(INCLUDES) -o $(NAME)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CXX) $^ $(FLAGS) -o $(NAME)

# $(OBJ_DIR)/%.o: %.cpp
# 	@mkdir -p $(@D)
# 	$(CXX) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean al

