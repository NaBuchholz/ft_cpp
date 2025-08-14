NAME = violence
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRCDIR = src
OBJDIR = build
INCDIR = includes
SRC = $(SRCDIR)/main.cpp \
	  $(SRCDIR)/HumanA.cpp \
	  $(SRCDIR)/HumanB.cpp \
	  $(SRCDIR)/Weapon.cpp 
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HPP) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
