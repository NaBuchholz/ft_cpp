NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCDIR = src
OBJDIR = build
INCDIR = includes

# COLORS
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
HEADERS = $(INCDIR)/PhoneBook.hpp $(INCDIR)/Contact.hpp

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed$(RESET)"

re: fclean all
	@echo "$(CYAN)Recompiled Exercise!$(RESET)"

.PHONY: all clean fclean re