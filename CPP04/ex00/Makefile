NAME = polymorphism

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/Animal.cpp \
      $(SRC_DIR)/Dog.cpp \
      $(SRC_DIR)/Cat.cpp \
      $(SRC_DIR)/WrongAnimal.cpp \
      $(SRC_DIR)/WrongCat.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
