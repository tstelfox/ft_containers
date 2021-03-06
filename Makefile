# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/14 16:41:04 by tmullan       #+#    #+#                  #
#    Updated: 2022/02/17 15:37:48 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = container
CXX = c++
SRC = vector_main.cpp
OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Isrc/vector -Isrc/map -Isrc/stack -Isrc/iterators -Isrc/utils

ifdef SEGS
	FLAGS += -fsanitize=address -g
endif
ifdef STL
	FLAGS += -DSTL
endif


map vector stack speed:
	@echo Compiling $@
	@$(CXX) src/$@_main.cpp $(FLAGS) $(INCLUDES) -o $(NAME)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CXX) $^ $(FLAGS) -o $(NAME)

# $(OBJ_DIR)/%.o: %.cpp
# 	@mkdir -p $(@D)
# 	$(CXX) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ rm -f $(NAME)
	@ rm -f *.txt

re: fclean al

