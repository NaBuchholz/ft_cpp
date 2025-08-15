NAME		= fragtrap
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCDIR		= src
INCDIR		= includes
OBJDIR		= obj

SOURCES		= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp
OBJECTS		= $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
HEADERS		= $(INCDIR)/ClapTrap.hpp $(INCDIR)/ScavTrap.hpp $(INCDIR)/FragTrap.hpp

# Colors
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
RED			= \033[0;31m
RESET		= \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	@echo "$(CYAN)Creating object directory...$(RESET)"
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(YELLOW)Cleaning objects...$(RESET)"
	@$(RM) -r $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning executable...$(RESET)"
	@$(RM) $(NAME)

re: fclean all
