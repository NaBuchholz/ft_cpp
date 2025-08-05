NAME = brainz
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

HPP = Zimbie.hpp
OBJDIR = build
SRCDIR = src

all: ${NAME}

$(NAME): $(SRC) $(HPP)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRCDIR)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
