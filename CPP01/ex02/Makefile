NAME = ref
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

OBJDIR = build
INCDIR = includes
SRC = main.cpp 
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
